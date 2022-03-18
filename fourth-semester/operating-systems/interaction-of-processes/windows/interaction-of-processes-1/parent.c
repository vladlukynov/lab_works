#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define STR_BUFFER_SIZE 10
#define PATH_BUFFER_SIZE 256
#define RADIX 10

HANDLE hEvent;
SECURITY_ATTRIBUTES SecurityAttributes;

int main(int argc, char* argv[])
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  SecurityAttributes.bInheritHandle = TRUE;

  STARTUPINFO startupInfo;
  PROCESS_INFORMATION processInfo;
  ZeroMemory(&startupInfo, sizeof(startupInfo));
  ZeroMemory(&processInfo, sizeof(processInfo));
  startupInfo.cb = sizeof(startupInfo);

  LPCWSTR path_ = L"C:\\Users\\vluky\\source\\repos\\interaction-of-processes-1\\x64\\Debug\\child.exe";
  WCHAR path[PATH_BUFFER_SIZE];
  wcscpy_s(path, PATH_BUFFER_SIZE, path_);

  LPCWSTR eventName = L"Event";
  hEvent = CreateEvent(&SecurityAttributes, TRUE, FALSE, eventName);
  if (hEvent == NULL)
  {
    printf("Event create error\n");
    return 1;
  }

  WCHAR str[STR_BUFFER_SIZE];
  _itow_s((int)hEvent, str, STR_BUFFER_SIZE, RADIX);
  wcscat_s(path, PATH_BUFFER_SIZE, L" ");
  wcscat_s(path, PATH_BUFFER_SIZE, str);

  if (!CreateProcess(NULL, path, NULL, NULL, TRUE, HIGH_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &processInfo))
  {
    printf("Could not create child process!\n");
    CloseHandle(hEvent);
    return 1;
  }

  printf("Дорогой дневник...\n");
  printf("Завещаю handle %ls процессу child\n", str);

  while (TRUE)
  {
    if (WaitForSingleObject(processInfo.hProcess, 100) != WAIT_TIMEOUT)
    {
      break;
    }
    while (TRUE)
    {
      char command[PATH_BUFFER_SIZE];
      printf("Enter command: ");
      scanf_s("%s", command, PATH_BUFFER_SIZE);
      if (strcmp(command, "exit") == 0)
      {
        TerminateProcess(processInfo.hProcess, 0);

        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);

        CloseHandle(hEvent);

        return 0;
      }
      else if (strcmp(command, "next") == 0)
      {
        SetEvent(hEvent);
        break;
      }
      else
      {
        printf("Error command\n");
      }
    }
    printf("Waiting child process...\n");
    WaitForSingleObject(hEvent, INFINITE);
    ResetEvent(hEvent);
  }

  printf("Child process terminated...\n");

  CloseHandle(processInfo.hProcess);
  CloseHandle(processInfo.hThread);

  CloseHandle(hEvent);

  return 0;
}
