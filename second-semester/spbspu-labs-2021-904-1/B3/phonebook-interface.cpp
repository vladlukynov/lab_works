#include "phonebook-interface.hpp"

#include <iostream>

PhoneBookInterface::PhoneBookInterface() :
  marks_{{"current", phoneBook.begin()}}
{}

void PhoneBookInterface::add(PhoneBook::record_t recordToAdd)
{
  const bool bookIsEmpty = phoneBook.isEmpty();
  phoneBook.add(recordToAdd);
  if (bookIsEmpty)
  {
    fixMarks();
  }
}

void PhoneBookInterface::show(const std::string &markName, std::ostream &output) const
{
  auto markIterator = marks_.find(markName);
  if (markIterator == marks_.end())
  {
    printInvalidBookmark(output);
    return;
  }
  if (phoneBook.isEmpty())
  {
    printEmpty(output);
    return;
  }
  output << markIterator->second->number << " " << markIterator->second->name << "\n";
}

void PhoneBookInterface::store(const std::string &markName, const std::string &newMarkName, std::ostream &output)
{
  auto markIterator = marks_.find(markName);
  if (markIterator == marks_.end())
  {
    printInvalidBookmark(output);
    return;
  }
  marks_[newMarkName] = markIterator->second;
}

void PhoneBookInterface::deleteMark(const std::string &markName, std::ostream &output)
{
  if (phoneBook.isEmpty())
  {
    printEmpty(output);
    return;
  }
  auto markIterator = marks_.find(markName);
  if (markIterator == marks_.end())
  {
    printInvalidBookmark(output);
    return;
  }
  auto deleteIter = markIterator->second;
  auto tempIter = markIterator->second;
  if (phoneBook.size() == 1)
  {
    phoneBook.deleteContact(deleteIter);
    return;
  }
  else if (tempIter == --phoneBook.end())
  {
    tempIter--;
  }
  else
  {
    tempIter++;
  }
  for (auto i = marks_.begin(); i != marks_.end(); i++)
  {
    if (i->second == deleteIter)
    {
      i->second = tempIter;
    }
  }
  phoneBook.deleteContact(deleteIter);
}

void PhoneBookInterface::moveToFirstOrLast(const std::string &markName, step_t step, std::ostream &output)
{
  if (phoneBook.isEmpty())
  {
    printEmpty(output);
    return;
  }
  auto markIter = marks_.find(markName);
  if (markIter == marks_.end())
  {
    printInvalidBookmark(output);
    return;
  }
  if (step == first)
  {
    markIter->second = phoneBook.begin();
  }
  else
  {
    markIter->second = --phoneBook.end();
  }
}

void PhoneBookInterface::moveOnSteps(const std::string &markName, int steps, std::ostream &output)
{
  if (phoneBook.isEmpty())
  {
    printEmpty(output);
    return;
  }
  auto markIter = marks_.find(markName);
  if (markIter == marks_.end())
  {
    printInvalidBookmark(output);
    return;
  }
  if (steps > 0)
  {
    if (std::distance(markIter->second, --phoneBook.end()) < steps)
    {
      markIter->second = --phoneBook.end();
    }
    else
    {
      markIter->second = std::next(markIter->second, steps);
    }
  }
  else if (steps < 0)
  {
    if (std::distance(phoneBook.begin(), markIter->second) < std::abs(steps))
    {
      markIter->second = phoneBook.begin();
    }
    else
    {
      markIter->second = std::prev(markIter->second, std::abs(steps));
    }
  }
}

void PhoneBookInterface::insertBefore(const std::string &markName, PhoneBook::record_t recordToAdd, std::ostream &output)
{
  auto markIter = marks_.find(markName);
  if (markIter == marks_.end())
  {
    printInvalidBookmark(output);
    return;
  }
  if (phoneBook.isEmpty())
  {
    phoneBook.add(recordToAdd);
    fixMarks();
    return;
  }
  phoneBook.insertBefore(recordToAdd, markIter->second);
}

void PhoneBookInterface::insertAfter(const std::string &markName, PhoneBook::record_t recordToAdd, std::ostream &output)
{
  auto markIter = marks_.find(markName);
  if (markIter == marks_.end())
  {
    printInvalidBookmark(output);
    return;
  }
  if (phoneBook.isEmpty())
  {
    phoneBook.add(recordToAdd);
    fixMarks();
    return;
  }
  phoneBook.insertAfter(recordToAdd, markIter->second);
}

void PhoneBookInterface::fixMarks()
{
  for (auto i = marks_.begin(); i != marks_.end(); i++)
  {
    i->second = phoneBook.begin();
  }
}

void PhoneBookInterface::printInvalidBookmark(std::ostream &output) const
{
  output << "<INVALID BOOKMARK>\n";
}

void PhoneBookInterface::printEmpty(std::ostream &output) const
{
  output << "<EMPTY>\n";
}
