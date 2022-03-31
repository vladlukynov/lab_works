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

#pragma omp parallel for
  for (int i = 0; i < 5; i++)
  {
    std::cout << "For: Thread " << omp_get_thread_num() << " print " << i << "\n";
    func();
  }

#pragma omp parallel
  {
#pragma omp sections nowait
    {
#pragma omp section
      for (int i = 0; i < 5; i++)
      {
        std::cout << "Sctions: Thread " << omp_get_thread_num() << " print 1\n";
        func();
      }
#pragma omp section
      for (int i = 0; i < 5; i++)
      {
        std::cout << "Sections: Thread " << omp_get_thread_num() << " print 2\n";
        func();
      }
    }

#pragma omp barrier
    {
      for (int i = 0; i < 5; i++)
      {
        std::cout << "Barrier: Thread " << omp_get_thread_num() << " print " << i << "\n";
        func();
      }
    }
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
