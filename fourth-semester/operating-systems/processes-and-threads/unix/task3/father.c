#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pid = getpid();
	int ppid = getppid();
	int status;

	printf("Father: pid=%i ppid=%i\n", pid, ppid);

	if (fork() == 0)
	{
		execl("son", "son", NULL);
	}

	sleep(4);
	system("ps -xf > task3.txt");

	return 0;
}
