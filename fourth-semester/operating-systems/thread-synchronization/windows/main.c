#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <stdio.h>

#define BUFF_SIZE 5
#define MAX_SIZE_CONSUMER 5
#define MAX_SIZE_PRODUCER 5

HANDLE allResourseBusy;
HANDLE allResourseFree;
HANDLE mutex;

int in = 0;
int out = 0;

int buffer[BUFF_SIZE];

DWORD WINAPI consumer(LPVOID lpParam);
DWORD WINAPI producer(LPVOID lpParam);

int main()
{
  HANDLE hProducerArray[MAX_SIZE_PRODUCER];
  HANDLE hConsumerArray[MAX_SIZE_CONSUMER];

  int nameProducerArray[MAX_SIZE_PRODUCER];
  int nameConsumerArray[MAX_SIZE_CONSUMER];

  allResourseBusy = CreateSemaphore(NULL, 0, BUFF_SIZE, NULL);
  if (allResourseBusy == NULL)
  {
    ExitProcess(3);
  }

  allResourseFree = CreateSemaphore(NULL, BUFF_SIZE, BUFF_SIZE, NULL);
  if (allResourseFree == NULL)
  {
    ExitProcess(3);
  }

  mutex = CreateMutex(NULL, FALSE, NULL);
  if (mutex == NULL)
  {
    ExitProcess(3);
  }

  for (int i = 0; i < MAX_SIZE_PRODUCER; i++)
  {
    nameProducerArray[i] = i;
    hProducerArray[i] = CreateThread(NULL, 0, producer, &nameProducerArray[i], 0, NULL);
    if (hProducerArray[i] == NULL)
    {
      ExitProcess(3);
    }
  }

  for (int i = 0; i < MAX_SIZE_CONSUMER; i++)
  {
    nameConsumerArray[i] = i;
    hConsumerArray[i] = CreateThread(NULL, 0, consumer, &nameConsumerArray[i], 0, NULL);

    if (hConsumerArray[i] == NULL)
    {
      ExitProcess(3);
    }
  }

  WaitForMultipleObjects(MAX_SIZE_PRODUCER, hProducerArray, TRUE, 1000);
  WaitForMultipleObjects(MAX_SIZE_CONSUMER, hConsumerArray, TRUE, 1000);

  for (int i = 0; i < MAX_SIZE_CONSUMER; i++)
  {
    CloseHandle(hConsumerArray[i]);
  }

  for (int i = 0; i < MAX_SIZE_PRODUCER; i++)
  {
    CloseHandle(hProducerArray[i]);
  }

  CloseHandle(allResourseFree);
  CloseHandle(allResourseBusy);
  CloseHandle(mutex);

  return 0;
}

DWORD WINAPI producer(LPVOID lpParam)
{
  while (TRUE)
  {
    int item = rand();
    if (WaitForSingleObject(allResourseFree, 100) == WAIT_OBJECT_0)
    {
      if (WaitForSingleObject(mutex, INFINITE) == WAIT_OBJECT_0)
      {
        buffer[in] = item;
        int indexProducer = *(int*)(lpParam);
        printf("Producer %d: produce item %d at %d\n", indexProducer, buffer[in], in);
        in = (in + 1) % BUFF_SIZE;
        ReleaseMutex(mutex);
      }
    }
    ReleaseSemaphore(allResourseBusy, 1, NULL);
  }

  return 0;
}

DWORD WINAPI consumer(LPVOID lpParam)
{
  while (TRUE)
  {
    if (WaitForSingleObject(allResourseBusy, 100) == WAIT_OBJECT_0)
    {
      if (WaitForSingleObject(mutex, INFINITE) == WAIT_OBJECT_0)
      {
        int item = buffer[out];
        int indexConsumer = *(int*)lpParam;
        printf("Consumer %d: consume item %d from %d\n", indexConsumer, item, out);
        out = (out + 1) % BUFF_SIZE;
        ReleaseMutex(mutex);
      }
    }
    ReleaseSemaphore(allResourseFree, 1, NULL);
  }

  return 0;
}
