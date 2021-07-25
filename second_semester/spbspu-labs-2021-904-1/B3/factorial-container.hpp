#ifndef FACTORIALCONTAINER_HPP
#define FACTORIALCONTAINER_HPP

#include <iterator>

class FactorialContainer
{
public:
  class const_iterator : public std::iterator<std::bidirectional_iterator_tag, size_t, ptrdiff_t, size_t, size_t>
  {
  public:
    reference operator*() const;
    const_iterator &operator++();
    const_iterator &operator--();
    const_iterator operator++(int);
    const_iterator operator--(int);
    bool operator==(const const_iterator &iterator) const;
    bool operator!=(const const_iterator &iterator) const;
  private:
    size_t index_;
    size_t maxIndex_;
    size_t value_;
    const_iterator(size_t index, size_t maxIndex, size_t value);
    friend FactorialContainer;
  };
  using iterator = const_iterator;
  using reverse_iterator = std::reverse_iterator<const_iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  FactorialContainer(size_t size = 0);
  const_iterator begin() const;
  const_iterator end() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
private:
  size_t maxIndex_;
  size_t maxValue_;
};

size_t calculateFactorialValue(size_t index);

#endif
