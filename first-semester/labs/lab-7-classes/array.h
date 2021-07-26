#ifndef ARRAY_H
#define ARRAY_H

#include "employee-card.h"

template<typename T>
class Array
{
public:
  Array();
  Array(int size);
  ~Array();
  void sortData(int size);
  T &operator[](int i);
private:
  T *data;
  int size = 0;
};

template<typename T>
Array<T>::Array()
{
  size = 0;
  data = nullptr;
}

template<typename T>
Array<T>::Array(int size)
{
  this->size = size;
  data = new T[size];
}

template<typename T>
Array<T>::~Array()
{
  delete[] data;
}

template<typename T>
T &Array<T>::operator[](int i)
{
  return data[i];
}

template<typename T>
void Array<T>::sortData(int size)
{
  EmployeeCard temp;
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (!(data[j] > data[i]))
      {
        temp = data[j];
        data[j] = data[i];
        data[i] = temp;
      }
    }
  }
}

#endif
