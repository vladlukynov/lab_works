#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define nitems 10
#define NBUFF 5
#define NP 3
#define NC 3

struct mystruct
{
    int buf[NBUFF];
    int first_empty;
    int first_full;
    sem_t *mutex, *nempty, *nstored;
} shared;

void *produce(void *arg)
{
    int i;
    while (sem_wait(shared.nempty) == 0)
    {
        if (sem_wait(shared.mutex) == 0)
        {
            i = rand();
            shared.buf[shared.first_empty] = i;
            shared.first_empty = (shared.first_empty + 1) % NBUFF;
            printf("Producing %d \n", i);
            sem_post(shared.mutex);
        }
        sem_post(shared.nstored);
    }

    return NULL;
}

void *consume(void *arg)
{
    int item;
    while (sem_wait(shared.nstored) == 0)
    {
        if (sem_wait(shared.mutex) == 0)
        {
            item = shared.buf[shared.first_full];
            shared.buf[shared.first_full] = -1;
            shared.first_full = (shared.first_full + 1) % NBUFF;
            printf("Consuming %d \n", item);
            sem_post(shared.mutex);
        }
        sem_post(shared.nempty);
    }

    return NULL;
}

int main(int argc, const char * argv[])
{   
    srand(time(NULL));

    shared.first_empty = 0;
    shared.first_full = 0;

    pthread_t tid_produce, tid_consume;

    shared.mutex = sem_open("/sem_mutex", O_CREAT, S_IROTH | S_IWOTH, 1);
    printf("%s\n", strerror(errno));

    shared.nempty = sem_open("/sem_nempty", O_CREAT, S_IROTH | S_IWOTH, NBUFF);
    printf("%s\n", strerror(errno));

    shared.nstored = sem_open("/sem_nstored", O_CREAT, S_IROTH | S_IWOTH, 0);
    printf("%s\n", strerror(errno));
    
    pthread_create(&tid_produce, NULL, produce, NULL);
    pthread_create(&tid_consume, NULL, consume, NULL);
    
    sleep(1);

    sem_unlink("/sem_mutex");
    sem_unlink("/sem_nempty");
    sem_unlink("/sem_nstored");

    return 0;
}
