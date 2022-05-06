#define MAXBUFF 256
#define PERM 0666

typedef struct our_msgbuf
{
    long mtype;
    char buff[MAXBUFF];
} Message;
