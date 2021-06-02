#include "functions.hpp"

#include <cstdlib>
#include <stdexcept>
#include <cstring>

sort_t getTypeOfSort(const char *sortType)
{
  if (sortType == nullptr)
  {
    throw std::invalid_argument("Empty sort type input");
  }
  if (!strcmp(sortType, "ascending"))
  {
    return ascending;
  }
  else if (!strcmp(sortType, "descending"))
  {
    return descending;
  }
  else
  {
    throw std::invalid_argument("Type of sort is not valid");
  }
}

void fillRandom(double *array, int size)
{
  if (size <= 0)
  {
    throw std::invalid_argument("Size must be more than 0");
  }
  if (array == nullptr)
  {
    throw std::invalid_argument("Array is empty");
  }
  for (int i = 0; i < size; i++)
  {
    array[i] = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
  }
}
