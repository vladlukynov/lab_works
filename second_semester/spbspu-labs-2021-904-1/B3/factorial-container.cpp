#include "factorial-container.hpp"

#include <stdexcept>

FactorialContainer::const_iterator::reference FactorialContainer::const_iterator::operator*() const
{
  return value_;
}

FactorialContainer::const_iterator &FactorialContainer::const_iterator::operator++()
{
  if ((index_ + 1) > maxIndex_)
  {
    throw std::out_of_range("Out of range of container");
  }
  index_++;
  value_ *= index_;
  return *this;
}

FactorialContainer::const_iterator &FactorialContainer::const_iterator::operator--()
{
  if ((index_ - 1) < 1)
  {
    throw std::out_of_range("Out of range of container");
  }
  index_--;
  value_ /= (index_ + 1);
  return *this;
}

FactorialContainer::const_iterator FactorialContainer::const_iterator::operator++(int)
{
  if ((index_ + 1) > maxIndex_)
  {
    throw std::out_of_range("Out of range of container");
  }
  FactorialContainer::const_iterator temp = *this;
  index_++;
  value_ *= index_;
  return temp;
}

FactorialContainer::const_iterator FactorialContainer::const_iterator::operator--(int)
{
  if ((index_ - 1) < 1)
  {
    throw std::out_of_range("Out of range of container");
  }
  FactorialContainer::const_iterator temp = *this;
  index_--;
  value_ /= (index_ + 1);
  return temp;
}

bool FactorialContainer::const_iterator::operator==(const const_iterator &iterator) const
{
  return iterator.value_ == value_;
}

bool FactorialContainer::const_iterator::operator!=(const const_iterator &iterator) const
{
  return iterator.value_ != value_;
}

FactorialContainer::const_iterator::const_iterator(size_t index, size_t maxIndex, size_t value) :
  index_(index),
  maxIndex_(maxIndex),
  value_(value)
{}

FactorialContainer::FactorialContainer(size_t size) :
  maxIndex_(size + 1),
  maxValue_(calculateFactorialValue(maxIndex_))
{}

FactorialContainer::const_iterator FactorialContainer::begin() const
{
  return const_iterator(1, maxIndex_, 1);
}

FactorialContainer::const_iterator FactorialContainer::end() const
{
  return const_iterator(maxIndex_, maxIndex_, maxValue_);
}

FactorialContainer::const_reverse_iterator FactorialContainer::rbegin() const
{
  return std::reverse_iterator<const_iterator>(end());
}

FactorialContainer::const_reverse_iterator FactorialContainer::rend() const
{
  return std::reverse_iterator<const_iterator>(begin());
}

size_t calculateFactorialValue(size_t index)
{
  size_t temp = 1;
  for (size_t i = 1; i <= index; i++)
  {
    if (temp > (SIZE_MAX / i))
    {
      throw std::overflow_error("Factorial container overflow");
    }
    temp *= i;
  }
  return temp;
}
