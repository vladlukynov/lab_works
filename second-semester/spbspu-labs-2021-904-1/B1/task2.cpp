#include "tasks.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <cstring>


#include "functions.hpp"

void task2(const char *fileName)
{
  if (fileName == nullptr)
  {
    throw std::invalid_argument("File name is empty");
  }
  std::ifstream input(fileName);
  if (!input)
  {
    throw std::runtime_error("File is not open");
  }
  size_t size = 0;
  size_t capacity = 1024;
  std::unique_ptr<char[]> collection(std::make_unique<char[]>(capacity));
  if (!collection)
  {
    throw std::bad_alloc();
  }
  while (input)
  {
    input.read(&collection[size], capacity - size);
    size += input.gcount();
    if (size == capacity)
    {
      std::unique_ptr<char[]> temp(std::make_unique<char[]>(capacity * 2));
      if (!temp)
      {
        throw std::bad_alloc();
      }
      std::memcpy(temp.get(), collection.get(), capacity);
      capacity *= 2;
      collection = std::move(temp);
    }
  }
  if (!input.eof())
  {
    throw std::runtime_error("File read error");
  }
  std::vector<char> vector(collection.get(), collection.get() + size);
  print(vector, "", std::cout);
}
