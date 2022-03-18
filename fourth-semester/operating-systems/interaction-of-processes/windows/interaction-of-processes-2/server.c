/* server */

#include <stdio.h>
#include <Windows.h>

#define BUFFER_SIZE 256

int main(int argc, char* argv[])
{
  HANDLE readPipe;
  HANDLE writePipe;

  HANDLE file;

  readPipe = (HANDLE)atoi(argv[1]);
  writePipe = (HANDLE)atoi(argv[2]);

  while (TRUE)
  {
    char str[BUFFER_SIZE];

    if (!ReadFile(readPipe, str, BUFFER_SIZE, NULL, NULL))
    {
      printf("Error path read\n");
      Sleep(2000);
      ExitProcess(1);
    }

    WCHAR path[256];
    mbstowcs_s(NULL, path, BUFFER_SIZE, str, BUFFER_SIZE);

    printf("Path: %ls\n", path);

    file = CreateFile(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (file == NULL)
    {
      printf("Error open file\n");
      Sleep(2000);
      ExitProcess(1);
    }

    ZeroMemory(str, sizeof(str));

    if (!ReadFile(file, str, BUFFER_SIZE, NULL, NULL))
    {
      printf("Error file read\n");
      Sleep(2000);
      ExitProcess(1);
    }

    printf("File read success\n");

    if (!WriteFile(writePipe, str, BUFFER_SIZE, NULL, NULL))
    {
      printf("Error message receive\n");
      Sleep(2000);
      ExitProcess(1);
    }

    printf("Message received to client\n");
  }

  Sleep(2000);
  return 0;
}
