/* Ќеобходимо обеспечить следующую функциональность :
       1. клиент считывает полное им€ файла из стандартного потока ввода и записывает его в канал;
       2. сервер считывает это им€ из канала и пытаетс€ открыть этот файл дл€ чтени€;
           2.1. если попытка успешна, то сервер считывает содержимое файла и записывает его в канал;
           2.2. в противном случае сервер возвращает клиенту сообщение об ошибке;
       3. клиент считывает данные из канала и записывает их в стандартный поток вывода. */

#include <stdio.h>
#include <Windows.h>

#define BUFFER_SIZE 256
#define RADIX 10

HANDLE readPipe;
HANDLE writePipe;
SECURITY_ATTRIBUTES pipeSA;

STARTUPINFO serverStartInfo;
STARTUPINFO clientStartInfo;

PROCESS_INFORMATION serverProcessInfo;
PROCESS_INFORMATION clientProcessInfo;

void createPipe();
void createClient();
void createServer();

int main()
{
  createPipe();
  createClient();
  createServer();

  printf("Waiting for stop server and client processes...\n");

  HANDLE processes[2] = { clientProcessInfo.hProcess , serverProcessInfo.hProcess };

  WaitForMultipleObjects(2, processes, FALSE, INFINITE);

  TerminateProcess(serverProcessInfo.hProcess, 0);
  TerminateProcess(clientProcessInfo.hProcess, 0);

  CloseHandle(readPipe);
  CloseHandle(writePipe);

  CloseHandle(serverProcessInfo.hProcess);
  CloseHandle(serverProcessInfo.hThread);

  CloseHandle(clientProcessInfo.hProcess);
  CloseHandle(clientProcessInfo.hThread);

  return 0;
}

void createPipe()
{
  pipeSA.bInheritHandle = TRUE;

  if (!CreatePipe(&readPipe, &writePipe, &pipeSA, 0))
  {
    printf("Pipe create error...\n");
    ExitProcess(1);
  }
}

void createClient()
{
  ZeroMemory(&clientStartInfo, sizeof(clientStartInfo));
  ZeroMemory(&clientProcessInfo, sizeof(clientProcessInfo));

  clientStartInfo.cb = sizeof(clientStartInfo);

  LPCWSTR clientPath_ = L"C:\\Users\\vluky\\source\\repos\\interaction-of-processes-2\\x64\\Debug\\client.exe";
  WCHAR clientPath[BUFFER_SIZE];
  wcscpy_s(clientPath, BUFFER_SIZE, clientPath_);

  WCHAR str[BUFFER_SIZE];
  _itow_s((int)readPipe, str, BUFFER_SIZE, RADIX);
  wcscat_s(clientPath, BUFFER_SIZE, L" ");
  wcscat_s(clientPath, BUFFER_SIZE, str);
  _itow_s((int)writePipe, str, BUFFER_SIZE, RADIX);
  wcscat_s(clientPath, BUFFER_SIZE, L" ");
  wcscat_s(clientPath, BUFFER_SIZE, str);

  if (!CreateProcess(NULL, clientPath, NULL, NULL, TRUE, HIGH_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL, &clientStartInfo, &clientProcessInfo))
  {
    CloseHandle(readPipe);
    CloseHandle(writePipe);

    printf("Client process create error\n");
    ExitProcess(1);
  }
}


void createServer()
{
  ZeroMemory(&serverStartInfo, sizeof(serverStartInfo));
  ZeroMemory(&serverProcessInfo, sizeof(serverProcessInfo));

  serverStartInfo.cb = sizeof(serverStartInfo);

  LPCWSTR serverPath_ = L"C:\\Users\\vluky\\source\\repos\\interaction-of-processes-2\\x64\\Debug\\server.exe";
  WCHAR serverPath[BUFFER_SIZE];
  wcscpy_s(serverPath, BUFFER_SIZE, serverPath_);

  WCHAR str[BUFFER_SIZE];
  _itow_s((int)readPipe, str, BUFFER_SIZE, RADIX);
  wcscat_s(serverPath, BUFFER_SIZE, L" ");
  wcscat_s(serverPath, BUFFER_SIZE, str);
  _itow_s((int)writePipe, str, BUFFER_SIZE, RADIX);
  wcscat_s(serverPath, BUFFER_SIZE, L" ");
  wcscat_s(serverPath, BUFFER_SIZE, str);

  if (!CreateProcess(NULL, serverPath, NULL, NULL, TRUE, HIGH_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL, &serverStartInfo, &serverProcessInfo))
  {
    CloseHandle(readPipe);
    CloseHandle(writePipe);

    CloseHandle(clientProcessInfo.hProcess);
    CloseHandle(clientProcessInfo.hThread);

    printf("Server process create error\n");
    ExitProcess(1);
  }
}
