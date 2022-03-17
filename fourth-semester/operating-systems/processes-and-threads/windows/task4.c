#include "tasks.h"

#include <stdio.h>
#include <Windows.h>
#include <time.h>

BOOL runFlag = TRUE;

DWORD WINAPI ThreadProcTask4(LPVOID lpParameter)
{
  int param;
  param = *(int*)lpParameter;

  while (TRUE)
  {
    printf("Thread %d is running!\n", param);

    Sleep(1000);

    if (runFlag == FALSE)
    {
      printf("Stop Thread %d!\n", param);
      ExitThread(0);
    }
  }
}

DWORD WINAPI ThreadScan(LPVOID lpParameter)
{
  struct tm endTime;
  endTime = *(struct tm *)lpParameter;

  while (TRUE)
  {
    time_t timer = time(NULL);
    struct tm currentTime;
    localtime_s(&currentTime, &timer);

    if ((currentTime.tm_hour > endTime.tm_hour) ||
      ((currentTime.tm_hour == endTime.tm_hour) && (currentTime.tm_min >= endTime.tm_min)))
    {
      runFlag = FALSE;
      Sleep(5000);
      printf("Stop ThreadScan!\n");
      ExitThread(0);
    }

    Sleep(1000);
  }
}

void task4(struct tm *endTime)
{
  HANDLE mHandle[2];
  DWORD mArg[2];
  DWORD mId[2];

  for (int i = 0; i < 1; i++)
  {
    mArg[i] = i;
    mHandle[i] = CreateThread(NULL, 0, ThreadProcTask4, mArg + i, 0, mId + i);
  }

  mHandle[1] = CreateThread(NULL, 0, ThreadScan, endTime, 0, mId + 1);

  while (runFlag == TRUE)
  {
    printf("Main is running!\n");
    Sleep(1000);
  }

  Sleep(10000);
}
