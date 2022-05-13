#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>

#include "shmem.h"

#define MAXMSGDATA 200

int shmid, semid;

void nulled_sems()
{
    int v1 = semctl(semid, 0, GETVAL);
    int v2 = semctl(semid, 1, GETVAL);
    int v3 = semctl(semid, 2, GETVAL);
    int v4 = semctl(semid, 3, GETVAL);
    v1 = -v1;
    v2 = -v2;
    v3 = -v3;
    v4 = -v4;
    struct sembuf nulled[4] = {
        0, v1, 0,
        1, v2, 0,
        2, v3, 0,
        3, v4, 0};
    if (semop(semid, &nulled[0], 4) < 0)
    {
        printf("Невозможно выполнить nulled\n");
        exit(1);
    }
}

int main()
{

    Message *msg;
    key_t key;

    int fd;
    char file[80];
    char text[11];

    //Получим ключ. Один и тот же ключ можно использовать как для семафора, так и для разделяемой памяти
    if ((key = ftok("server", 'A')) < 0)
    {
        printf("Невозможно получить ключ\n");
        exit(1);
    }

    //Создадим область разделяемой памяти
    if ((shmid = shmget(key, sizeof(Message), PERM | IPC_CREAT)) < 0)
    {
        printf("Невозможно создать область\n");
        exit(1);
    }

    //Присоединим ее
    if ((msg = (Message *)shmat(shmid, 0, 0)) < 0)
    {
        printf("Ошибка присоединения\n");
        exit(1);
    }

    //Создадим группу из двух семафоров:
    //Первый семафор – для синхронизации работы с разделяемой памятью
    //Второй семафор – для синхронизации выполнения процессов
    if ((semid = semget(key, 4, PERM | IPC_CREAT)) < 0)
    {
        printf("Невозможно создать семафор\n");
        exit(1);
    }

    nulled_sems();

    printf("Server was start\n");

    FILE *fp;
    // Ждем уведомления от клиента
    if (semop(semid, &wait_client_notify[0], 1) < 0)
    {
        printf("Невозможно выполнить wait_client_notify\n");
        exit(1);
    }

    // Ждем когда клиент освободит память и блокируем ее
    if (semop(semid, &mem_wait_lock[0], 2) < 0)
    {
        printf("Невозможно выполнить mem_wait_lock\n");
        exit(1);
    }

    // Читаем из файла и записываем в разделяемую память
    if ((fp = fopen(msg->buff, "r")) == NULL)
    {
        printf("File '%s' doesn't exist\n", msg->buff);
        sprintf(msg->buff, "Cannot open file");
    }
    else
    {
        while (fgets(msg->buff, MAXMSGDATA, fp) != NULL)
        {
            printf("Server write: %s\n", msg->buff);
        }
        fclose(fp);
    }

    // Освобождаем память
    if (semop(semid, &mem_unlock[0], 1) < 0)
    {
        printf("Невозможно выполнить mem_unlock\n");
        exit(1);
    }

    // Уведомляем клиента о завершении работы сервера
    if (semop(semid, &notify_client[0], 1) < 0)
    {
        printf("Невозможно выполнить mem_unlock\n");
        exit(1);
    }

    exit(0);
}
