#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
  HANDLE hfile = CreateFile(
    L"file.txt",
    GENERIC_READ | GENERIC_WRITE,
    FILE_SHARE_READ | FILE_SHARE_WRITE,
    NULL,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    NULL
  );

  if (hfile == INVALID_HANDLE_VALUE)
  {
    printf("Can't open file. Error %d\n", GetLastError());
    exit(GetLastError());
  }

  HANDLE hfilemap = CreateFileMapping(
    hfile,
    NULL,
    PAGE_READWRITE,
    0,
    0,
    L"filemap");
  if (hfilemap == INVALID_HANDLE_VALUE)
  {
    printf("Can't create file mapping. Error %d\n", GetLastError());
    exit(GetLastError());
  }

  DWORD dwFileSize = GetFileSize(hfile, NULL);

  CloseHandle(hfile);

  LPVOID pvfile = MapViewOfFile(
    hfilemap,
    FILE_MAP_ALL_ACCESS,
    0,
    0,
    dwFileSize);

  CloseHandle(hfilemap);

  LPSTR pchANSI = (LPSTR)pvfile;
  for (DWORD i = 0; i < dwFileSize; i++)
  {
    printf("%c", pchANSI[i]);
  }

  for (DWORD i = 0; i < dwFileSize; i++)
  {
    pchANSI[i] = 'T';
  }

  UnmapViewOfFile(pvfile);

  return(0);
}
