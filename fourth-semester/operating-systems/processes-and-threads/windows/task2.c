#include "tasks.h"

#include <stdio.h>
#include <Windows.h>

void createProcess(LPWSTR path)
{
  STARTUPINFO startupInfo;
  PROCESS_INFORMATION processInfo;

  ZeroMemory(&startupInfo, sizeof(startupInfo));
  ZeroMemory(&processInfo, sizeof(processInfo));

  startupInfo.cb = sizeof(startupInfo);

  WCHAR program[256];

  wcscpy_s(program, wcslen(path) + 1, path);

  if (!CreateProcess(NULL, program, NULL, NULL, FALSE,
    HIGH_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL,
    &startupInfo, &processInfo))
  {
    fprintf(stderr, "CreateProcess failed on error %d\n", GetLastError());
    ExitProcess(1);
  }

  HANDLE processHandle = processInfo.hProcess;
  HANDLE threadHandle = processInfo.hThread;

  printf("Process handle: %i\n", (int)processHandle);
  printf("Thread handle: %i\n", (int)threadHandle);

  CloseHandle(processHandle);
  CloseHandle(threadHandle);
}

void task2(const char* path)
{
  FILE* file;
  fopen_s(&file, path, "r");

  if (file == NULL) {
    fprintf(stderr, "File not opened\n");
    ExitProcess(1);
  }

  WCHAR process[256];

  while (!feof(file))
  {
    fscanf_s(file, "%ws", &process, 256);
    createProcess(process);
  }
  
  fclose(file);
}
