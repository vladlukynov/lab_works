#include <stdio.h>
#include <Windows.h>
#include <time.h>

#include "tasks.h"

int main(int argc, char *argv[])
{
  /* Task 1 */

  printf("Starting task 1\n");
  task1();

  /* Task 2 */

  printf("Starting task 2\n");
  if (argc != 2)
  {
    fprintf(stderr, "Wrong number of arguments\n");
    ExitProcess(1);
  }
  task2(argv[1]);

  /* Task 3 */

  printf("Starting task 3\n");
  task3();

  /* Task 4 */

  struct tm endTime;
  endTime.tm_hour = 6;
  endTime.tm_min = 5;

  printf("Starting task 4\n");
  task4(&endTime);

  return 0;
}
