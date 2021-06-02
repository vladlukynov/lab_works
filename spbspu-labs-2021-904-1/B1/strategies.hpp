#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

template<class T>
struct IndexAccess
{
  using iterator = typename T::size_type;
  using value = typename T::value_type;
  static iterator begin(const T &)
  {
    return 0;
  }
  static iterator end(const T &container)
  {
    return container.size();
  }
  static value &get(T &container, iterator index)
  {
    return container[index];
  }
};

template<class T>
struct AtAccess
{
  using iterator = typename T::size_type;
  using value = typename T::value_type;
  static iterator begin(const T &)
  {
    return 0;
  }
  static iterator end(const T &container)
  {
    return container.size();
  }
  static value &get(T &container, iterator index)
  {
    return container.at(index);
  }
};

template<class T>
struct AccessWithIterators
{
  using iterator = typename T::iterator;
  using value = typename T::value_type;
  static iterator begin(T &container)
  {
    return container.begin();
  }
  static iterator end(T &container)
  {
    return container.end();
  }
  static value &get(const T &, iterator index)
  {
    return *index;
  }
};

#endif
