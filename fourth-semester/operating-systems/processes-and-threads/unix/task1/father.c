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
	system("ps -xf > task1.txt");
	wait(&status);
	printf("Son stopeed with %i status\n", status);

	return 0;
}
