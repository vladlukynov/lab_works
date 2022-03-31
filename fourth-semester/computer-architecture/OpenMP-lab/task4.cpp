#include <omp.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define NUM_OF_THREADS 2

void func();

int main()
{
  omp_set_num_threads(NUM_OF_THREADS);

  omp_lock_t lock;
  omp_init_lock(&lock);

#pragma omp parallel for
  for (int i = 0; i < 5; i++)
  {
    while (!omp_test_lock(&lock))
    {
      std::cout << "Thread " << omp_get_thread_num() << " is waiting\n";
      func();
    }
    std::cout << "Thread " << omp_get_thread_num() << " set lock\n";

    func();

    std::cout << "Thread " << omp_get_thread_num() << " unset lock\n";
    omp_unset_lock(&lock);
  }

  return 0;
}

void func()
{
  for (int i = 0; i < 500000; i++)
  {
    int temp = rand();
  }
}
