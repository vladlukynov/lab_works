#include "tasks.h"

#include <stdio.h>
#include <Windows.h>

DWORD WINAPI ThreadProcTask3(LPVOID lpParameter)
{
  int param;
  param = *(int*)lpParameter;

  printf("I am Thread %d. Hello!\n", param);

  while (TRUE)
  {
    printf("Thread %d is running!\n", param);

    Sleep(100);
  }
}

void task3()
{
  HANDLE mHandle[2];
  DWORD mArg[2];
  DWORD mId[2];

  printf("I am main! Hello!\n");

  for (int i = 0; i < 2; i++)

  {
    mArg[i] = i;
    mHandle[i] = CreateThread(NULL, 0, ThreadProcTask3, mArg + i, 0, mId + i);
  }

  Sleep(1000);

  //while(TRUE)
  //{
  //  printf("Main in while!\n");
  //  Sleep(1000);
  //}
}
