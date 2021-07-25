#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <list>

class PhoneBook
{
public:
  struct record_t
  {
    std::string number;
    std::string name;
  };

  using iterator = typename std::list<record_t>::iterator;
  using const_iterator = typename std::list<record_t>::const_iterator;

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  const_iterator cbegin() const;
  const_iterator cend() const;

  void add(record_t recordToAdd);
  void deleteContact(iterator iter);

  void insertBefore(record_t recordToAdd, iterator iter);
  void insertAfter(record_t recordToAdd, iterator iter);

  bool isEmpty() const;
  size_t size() const;
private:
  std::list<record_t> records_;
};

#endif
