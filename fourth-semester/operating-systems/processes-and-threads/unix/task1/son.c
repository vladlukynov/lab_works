#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid = getpid();
	int ppid = getppid();

	printf("Son: pid=%i ppid=%i\n", pid, ppid);

	sleep(2);

	return 0;
}
