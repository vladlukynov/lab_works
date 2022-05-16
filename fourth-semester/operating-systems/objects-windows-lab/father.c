#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

struct handles {
	HANDLE tHandle;
	HANDLE pHandle;
};

struct handles createProcess(LPWSTR path, STARTUPINFO* startupInfo, PROCESS_INFORMATION* processInfo, int K);

int main(int argc, char* argv[])
{
	srand(time(NULL));

	if (argc != 3) {
		fprintf(stderr, "Wrong number of arguments\n");
		return 1;
	}

	int N = atoi(argv[1]);
	int K = atoi(argv[2]);

	STARTUPINFO* startupInfo;
	PROCESS_INFORMATION* processInfo;
	HANDLE* tHandles;
	HANDLE* pHandles;
	startupInfo = calloc(N, sizeof(STARTUPINFO));
	processInfo = calloc(N, sizeof(PROCESS_INFORMATION));
	tHandles = calloc(N, sizeof(HANDLE));
	pHandles = calloc(N, sizeof(HANDLE));

	LPWSTR processPath = L"C:\\Users\\Vladislav\\source\\repos\\objects\\x64\\Debug\\son.exe";

	for (int i = 0; i < N; i++)
	{
		int K_ = rand() % 21 + (K - 10);
		struct handles handles_ = createProcess(processPath, startupInfo + i, processInfo + i, K_);
		tHandles[i] = handles_.tHandle;
		pHandles[i] = handles_.pHandle;
	}

	printf("Wait %i seconds...\n", K);
	Sleep(K * 1000);

	for (int i = 0; i < N; i++)
	{
		TerminateProcess(pHandles[i], 0);
		CloseHandle(tHandles[i]);
		CloseHandle(pHandles[i]);
	}

	free(startupInfo);
	free(processInfo);
	free(tHandles);
	free(pHandles);

	return 0;
}

struct handles createProcess(LPWSTR path, STARTUPINFO* startupInfo, PROCESS_INFORMATION* processInfo, int K)
{
	startupInfo->cb = sizeof(STARTUPINFO);

	WCHAR program[256];
	WCHAR K_[64];
	_itow_s(K, K_, 64, 10);
	wcscpy_s(program, wcslen(path) + 1, path);
	wcscat_s(program, wcslen(program) + wcslen(L" ") + 1, L" ");
	wcscat_s(program, wcslen(program) + wcslen(K_) + 1, K_);

	if (!CreateProcess(NULL, program, NULL, NULL, FALSE, HIGH_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL, startupInfo, processInfo))
	{
		fprintf(stderr, "Create process error: %d\n", GetLastError());
		ExitProcess(1);
	}

	struct handles handles_ = { processInfo->hThread, processInfo->hProcess };
	return handles_;
}
