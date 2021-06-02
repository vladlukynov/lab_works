#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "strategies.hpp"

enum sort_t
{
  ascending, descending
};

sort_t getTypeOfSort(const char *sortType);
void fillRandom(double *array, int size);

template<template<typename Container> class Access, typename Container>
void sort(Container &container, const sort_t &sortType)
{
  using iterator = typename Access<Container>::iterator;
  iterator begin = Access<Container>::begin(container);
  iterator end = Access<Container>::end(container);
  for (iterator i = begin; i != end; i++)
  {
    for (iterator j = i; j != end; j++)
    {
      typename Container::value_type &element1 = Access<Container>::get(container, i);
      typename Container::value_type &element2 = Access<Container>::get(container, j);
      if (sortType == ascending)
      {
        if (element2 < element1)
        {
          std::swap(element1, element2);
        }
      }
      else if (sortType == descending)
      {
        if (element2 > element1)
        {
          std::swap(element1, element2);
        }
      }
    }
  }
}

template<typename Container>
void print(const Container &container, const char *separator, std::ostream &output)
{
  if (separator == nullptr)
  {
    throw std::invalid_argument("Empty separator");
  }
  using iterator = typename Container::const_iterator;
  for (iterator i = container.cbegin(); i != container.cend(); i++)
  {
    output << *i << separator;
  }
}

#endif
