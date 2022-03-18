#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define STR_BUFFER_SIZE 256

HANDLE hEvent;

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Invalid parameter!\n");
    return 0;
  }

  hEvent = (HANDLE)atoi(argv[1]);

  while (TRUE)
  {
    printf("Wait parent...\n");
    WaitForSingleObject(hEvent, INFINITE);
    ResetEvent(hEvent);
    while (TRUE)
    {
      char command[STR_BUFFER_SIZE];
      printf("Enter command: ");
      scanf_s("%s", command, STR_BUFFER_SIZE);
      if (strcmp(command, "exit") == 0)
      {
        SetEvent(hEvent);
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
  }

  return 0;
}
