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

void client_work(char *file_name);

Message *msg;
int shmid, semid;
key_t key;
int fd;

int main()
{
    //Получим ключ. Один и тот же ключ можно использовать как для семафора, так и для разделяемой памяти
    if ((key = ftok("server", 'A')) < 0)
    {
        printf("Невозможно получить ключ\n", 1);
        exit(1);
    }

    //Получим доступ к разделяемой памяти
    if ((shmid = shmget(key, sizeof(Message), 0)) < 0)
    {
        printf("Ошибка доступа\n");
        exit(1);
    }

    //Присоединим ее
    if ((msg = (Message *)shmat(shmid, 0, 0)) < 0)
    {
        printf("Ошибка присоединения\n");
        exit(1);
    }

    //Получим доступ к семафору
    if ((semid = semget(key, 2, PERM)) < 0)
    {
        printf("Ошибка доступа\n");
        exit(1);
    }

    char *file_name[30];
    printf("Enter file name: ");
    gets(file_name);
    client_work(file_name);

    exit(0);
}

void client_work(char *file_name)
{
    // Ожидаем завершение работы других клиентов и блокируем ресурс
    if (semop(semid, &client_wait_lock[0], 2) < 0)
    {
        printf("Невозможно выполнить client_wait_lock\n");
        exit(1);
    }

    // Блокируем разделяемую память
    if (semop(semid, &mem_wait_lock[0], 2) < 0)
    {
        printf("Невозможно выполнить mem_wait_lock\n");
        exit(1);
    }

    // Уведомляем сервер о начале работы клиента
    if (semop(semid, &notify_server[0], 1) < 0)
    {
        printf("Невозможно выполнить server_notify\n");
        exit(1);
    }

    // Записываем в разделяемую память
    sprintf(msg->buff, file_name);

    // Освобождаем память
    if (semop(semid, &mem_unlock[0], 1) < 0)
    {
        printf("Невозможно выполнить mem_unlock\n");
        exit(1);
    }

    // Ждем пока сервер завершит работу и освободит память
    if (semop(semid, &wait_server_notify[0], 1) < 0)
    {
        printf("Невозможно выполнить wait_server_notify\n");
        exit(1);
    }

    // Блокируем разделяемую память
    if (semop(semid, &mem_wait_lock[0], 2) < 0)
    {
        printf("Невозможно выполнить mem_wait_lock\n");
        exit(1);
    }

    // Выводим из разделяемой памяти
    printf("Server return: %s\n", msg->buff);

    // Разблокируем память
    if (semop(semid, &mem_unlock[0], 1) < 0)
    {
        printf("Невозможно выполнить mem_unlock2\n");
        exit(1);
    }

    // Освобождаем ресурс для возможности работы других клиентов
    if (semop(semid, &client_unlock[0], 1) < 0)
    {
        printf("Невозможно выполнить client_unlock\n");
        exit(1);
    }
}
