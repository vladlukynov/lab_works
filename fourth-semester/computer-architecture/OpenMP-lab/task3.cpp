#include <omp.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define NUM_OF_THREADS 5

int main()
{
  int firstValue = 0;
  int secondValue = 0;

  omp_set_num_threads(NUM_OF_THREADS);

#pragma omp parallel for
  for (int i = 0; i < 10; i++)
  {
#pragma omp critical
    std::cout << "First value: Thread " << omp_get_thread_num() << " print " << firstValue++ << "\n";
  }

#pragma omp parallel for
  for (int i = 0; i < 50; i++)
  {
#pragma omp atomic
      secondValue++;
  }

  std::cout << "Second value: " << secondValue << "\n";

  return 0;
}
