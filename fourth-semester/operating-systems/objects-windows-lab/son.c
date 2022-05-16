#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define _SECOND 10000000

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments\n");
		return 1;
	}

	int K = atoi(argv[1]);
	printf("Wait %i seconds...\n", K);

	// Create waitable timer
	__int64 endTime;
	LARGE_INTEGER quitTime;
	HANDLE wTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	if (wTimer == NULL)
	{
		fprintf(stderr, "Waitable timer create error: %i", GetLastError());
		return 1;
	}
	endTime = -K * _SECOND;
	quitTime.LowPart = (DWORD)(endTime & 0xFFFFFFFF);
	quitTime.HighPart = (LONG)(endTime >> 32);
	SetWaitableTimer(wTimer, &quitTime, 0, NULL, NULL, FALSE);

	WaitForSingleObject(wTimer, INFINITE);

	CloseHandle(wTimer);

	return 0;
}
