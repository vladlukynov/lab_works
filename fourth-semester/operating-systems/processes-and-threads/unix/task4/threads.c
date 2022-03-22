#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAXTHREADS 2
#define TRUE 1

void *produce(void *arg);

int main()
{
  int count[MAXTHREADS];
  pthread_t tid_produce[MAXTHREADS];
  for (int i = 0; i < MAXTHREADS; i++)
  {
    count[i] = i;
    pthread_create(&tid_produce[i], NULL, produce, &count[i]);
  }

  for (int i = 0; i < MAXTHREADS; i++)
  {
    pthread_join(tid_produce[i], NULL);
  }

  printf("All threads stopped\n");

  exit(0);
}

void *produce(void *arg)
{
  int i = 0;

  while (i <= 10)
  {
    printf("Thread %d is running. tid = %li. Local value = %i.\n", *(int *)arg, pthread_self(), i);
    i++;
    sleep(1);
  }
  return (NULL);
}
