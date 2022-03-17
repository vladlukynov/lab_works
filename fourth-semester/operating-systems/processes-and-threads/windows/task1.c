#include "tasks.h"

#include <stdio.h>
#include <Windows.h>

void task1()
{
  STARTUPINFO startupInfo;
  PROCESS_INFORMATION processInfo;

  ZeroMemory(&startupInfo, sizeof(startupInfo));
  ZeroMemory(&processInfo, sizeof(processInfo));

  startupInfo.cb = sizeof(startupInfo);

  LPCWSTR path = L"C:\\Windows\\System32\\notepad.exe";

  WCHAR program[256];

  wcscpy_s(program, wcslen(path) + 1, path);

  printf("%ws\n", program);

  if (!CreateProcess(NULL, program, NULL, NULL, FALSE, HIGH_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &processInfo))
  {
    fprintf(stderr, "CreateProcess failed on error %d\n", GetLastError());
    ExitProcess(1);
  }

  HANDLE processHandle = processInfo.hProcess;
  HANDLE threadHandle = processInfo.hThread;

  printf("Process handle: %i\n", (int)processHandle);
  printf("Thread handle: %i\n", (int)threadHandle);

  printf("Waiting that notepad has been closed\n");
  WaitForSingleObject(processInfo.hProcess, INFINITE);

  CloseHandle(processHandle);
  CloseHandle(threadHandle);
}
