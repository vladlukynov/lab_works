#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	sleep(2);

	int pid = getpid();
	int ppid = getppid();

	system("ps -xf > task2.txt");

	printf("Son: pid=%i ppid=%i\n", pid, ppid);

	return 0;
}
