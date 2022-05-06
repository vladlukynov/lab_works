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
int msgid, length;

int main()
{
    message.mtype = 1L;

    if ((key = ftok("server", 'A')) < 0)
    {
        printf("Невозможно получить ключ\n");
        exit(1);
    }

    if ((msgid = msgget(key, 0)) < 0)
    {
        printf("Невозможно получить доступ к очереди\n");
        exit(1);
    }
    
    while (TRUE)
    {
        printf("Введите сообщение: ");
        fgets(message.buff, MAXBUFF, stdin);
        length = strlen(message.buff);

        if (msgsnd(msgid, (void *)&message, length, 0) != 0)
        {
            printf("Ошибка записи сообщения в очередь\n");
            exit(1);
        }

        Message temp_msg;
        temp_msg.mtype = message.mtype;

        length = msgrcv(msgid, &temp_msg, sizeof(temp_msg), temp_msg.mtype, 0);
        if (length == 0)
        {
            printf("Ошибка чтения сообщения\n");
            exit(1);
        }
        printf("%s\n", temp_msg.buff);
    }

    if (msgctl(msgid, IPC_RMID, 0) < 0)
    {
        printf("Ошибка удаления очереди\n");
        exit(1);
    }
    return 0;
}
