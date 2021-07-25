#include "phonebook.hpp"

#include <stdexcept>

PhoneBook::iterator PhoneBook::begin()
{
  return records_.begin();
}

PhoneBook::const_iterator PhoneBook::begin() const
{
  return records_.begin();
}

PhoneBook::iterator PhoneBook::end()
{
  return records_.end();
}

PhoneBook::const_iterator PhoneBook::end() const
{
  return records_.end();
}

PhoneBook::const_iterator PhoneBook::cbegin() const
{
  return records_.cbegin();
}

PhoneBook::const_iterator PhoneBook::cend() const
{
  return records_.cend();
}

void PhoneBook::add(record_t recordToAdd)
{
  if (recordToAdd.number.empty() || recordToAdd.name.empty())
  {
    throw std::invalid_argument("Incorrect information to add to phonebook");
  }
  records_.push_back(recordToAdd);
}

void PhoneBook::deleteContact(iterator iter)
{
  if (records_.empty())
  {
    throw std::logic_error("Phonebook is empty");
  }
  records_.erase(iter);
}

void PhoneBook::insertBefore(record_t recordToAdd, iterator iter)
{
  if (records_.empty())
  {
    records_.push_back(recordToAdd);
    return;
  }
  if (iter == records_.begin())
  {
    records_.push_front(recordToAdd);
  }
  else
  {
    records_.insert(iter, recordToAdd);
  }
}

void PhoneBook::insertAfter(record_t recordToAdd, iterator iter)
{
  if (records_.empty())
  {
    records_.push_back(recordToAdd);
    return;
  }
  if (iter == --records_.end())
  {
    records_.push_back(recordToAdd);
  }
  else
  {
    iter++;
    records_.insert(iter, recordToAdd);
  }
}

bool PhoneBook::isEmpty() const
{
  return records_.empty();
}

size_t PhoneBook::size() const
{
  return records_.size();
}
