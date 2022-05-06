#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig);
void set_action(int sig, struct sigaction *new_action, struct sigaction *old_action);
void restore_action(int sig, struct sigaction *old_action);
void sigint_hanlder(int sig);

int main()
{

    struct sigaction new_usr1_action, old_usr1_action, new_usr2_action, old_usr2_action;

    struct sigaction act;
    struct sigaction oldact;

    printf("Sigact pid=%i\n", getpid());

    set_action(SIGUSR1, &new_usr1_action, &old_usr1_action);
    set_action(SIGUSR2, &new_usr2_action, &old_usr2_action);
    
    act.sa_handler = sigint_hanlder;
    sigaction(SIGINT, &act, &oldact);

    kill(getpid(), SIGUSR1);

    sleep(60);
    
    restore_action(SIGUSR1, &old_usr1_action);
    restore_action(SIGUSR2, &old_usr2_action);
    restore_action(SIGINT, &oldact);
    
    return 0;
}

void sig_handler(int sig)
{
    printf("Signal %i is comming\n", sig);

    kill(getpid(), SIGINT);

    sleep(10);
}

void sigint_hanlder(int sig)
{
    printf("SIGINT IS COMMING\n");
    exit(0);
}

void set_action(int sig, struct sigaction *new_action, struct sigaction *old_action)
{
    new_action->sa_handler = sig_handler;

    sigemptyset(&(new_action->sa_mask));
    sigaddset(&(new_action->sa_mask), SIGINT);

    new_action->sa_flags = 0;

    sigaction(sig, new_action, old_action);

    printf("Action is setted\n");
    return;
}

void restore_action(int sig, struct sigaction *old_action)
{
    sigaction(sig, old_action, NULL);

    printf("We restored action!\n");
    return;
}
