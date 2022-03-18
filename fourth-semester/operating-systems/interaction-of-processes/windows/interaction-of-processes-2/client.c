/* client */

#include <stdio.h>
#include <Windows.h>

#define BUFFER_SIZE 256

int main(int argc, char* argv[])
{
  HANDLE readPipe;
  HANDLE writePipe;

  readPipe = (HANDLE)atoi(argv[1]);
  writePipe = (HANDLE)atoi(argv[2]);

  while (TRUE)
  {
    char str[BUFFER_SIZE];

    printf("Enter \"exit\" to stop program\n");
    printf("Enter file path: ");
    scanf_s("%s", str, BUFFER_SIZE);

    if (strcmp(str, "exit") == 0)
    {
      ExitProcess(0);
    }

    if (!WriteFile(writePipe, str, BUFFER_SIZE, NULL, NULL))
    {
      printf("Error receive message to server\n");
      Sleep(2000);
      ExitProcess(1);
    }

    ZeroMemory(str, sizeof(str));

    if (!ReadFile(readPipe, str, BUFFER_SIZE, NULL, NULL))
    {
      printf("Error get message from server\n");
      Sleep(2000);
      ExitProcess(1);
    }

    printf("%s\n", str);
  }

  Sleep(2000);
  return 0;
}
