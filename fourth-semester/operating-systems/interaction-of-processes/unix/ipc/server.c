#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

#include "mesg.h"

#define TRUE 1

Message message;
key_t key;
int msgid, length, n;

void sigint_handler(int sig);

int main()
{
    struct sigaction action, oldaction;
    action.sa_handler = sigint_handler;
    sigaction(SIGINT, &action, &oldaction);

    if ((key = ftok("server", 'A')) < 0)
    {
        printf("Невозможно получить ключ\n");
        exit(1);
    }

    message.mtype = 1L;

    if ((msgid = msgget(key, PERM | IPC_CREAT)) < 0)
    {
        printf("Невозможно создать очередь\n");
        exit(1);
    }

    while (TRUE)
    {
        printf("Ожидание сообщения...\n");

        n = msgrcv(msgid, &message, sizeof(message), message.mtype, 0);
        if (n == 0)
        {
            printf("Ошибка чтения сообщения\n");
            exit(1);
        }
        printf("Получено: %s\n", message.buff);

        Message temp_msg;
        temp_msg.mtype = message.mtype;
        temp_msg.buff[0] = '\0';
        strcat(temp_msg.buff, "Ваше сообщение: ");
        strcat(temp_msg.buff, message.buff);

        if (msgsnd(msgid, (void *)&temp_msg, strlen(temp_msg.buff), 0) != 0)
        {
            printf("Ошибка записи сообщения в очередь\n");
            exit(1);
        }
    }

    sigaction(SIGINT, &oldaction, NULL);
    return 0;
}

void sigint_handler(int sig)
{
    printf("Очистка очереди\n");
    if (msgctl(msgid, IPC_RMID, 0) < 0)
    {
        printf("Ошибка удаления очереди\n");
        exit(1);
    }
    exit(0);
}
