#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>

#define PAGE_LIMIT 2

LPTSTR lpNxtPage;
DWORD dwPages = 0;
DWORD dwPageSize;

int pageFaultExceptionFilter(DWORD errorCode)
{
  LPVOID lpvResult;

  if (dwPages >= PAGE_LIMIT)
  {
    printf("Page limit exception\n");
    return EXCEPTION_EXECUTE_HANDLER;
  }

  lpvResult = VirtualAlloc(
    (LPVOID)lpNxtPage,
    dwPageSize,
    MEM_COMMIT,
    PAGE_READWRITE);

  if (lpvResult == NULL)
  {
    printf("Commit page error\n");
    return EXCEPTION_EXECUTE_HANDLER;
  }

  dwPages++;
  lpNxtPage = (LPTSTR)((PCHAR)lpNxtPage + dwPageSize);

  return EXCEPTION_CONTINUE_EXECUTION;
}

int main()
{
  LPVOID lpvBase;
  LPTSTR lpPtr;
  SYSTEM_INFO sSysInfo;

  GetSystemInfo(&sSysInfo);
  printf("This computer has page size %d\n", sSysInfo.dwPageSize);
  dwPageSize = sSysInfo.dwPageSize;

  lpvBase = VirtualAlloc(
    NULL,
    PAGE_LIMIT * dwPageSize,
    MEM_RESERVE,
    PAGE_NOACCESS);

  if (lpvBase == NULL)
  {
    printf("VirtualAlloc reserve failed\n");
    return 1;
  }

  lpPtr = (LPTSTR)lpvBase;
  lpNxtPage = (LPTSTR)lpvBase;

  for (DWORD i = 0; i < PAGE_LIMIT * dwPageSize; i++)
  {
    __try
    {
      lpPtr[i] = 'A';
      printf("Write A to memory; i = %i\n", i);
    }
    __except (pageFaultExceptionFilter(GetExceptionCode()))
    {
      printf("Exiting process\n");
      break;
    }
  }

  BOOL bSuccess = VirtualFree(
    lpvBase,
    0,
    MEM_RELEASE);

  if (bSuccess == FALSE)
  {
    printf("Error with VirtualFree()\n");
    return 1;
  }

  return 0;
}
