#ifndef PHONEBOOKINTERFACE_HPP
#define PHONEBOOKINTERFACE_HPP

#include "phonebook.hpp"

#include <unordered_map>

class PhoneBookInterface
{
public:
  enum step_t
  {
    first, last
  };

  PhoneBookInterface();
  void add(PhoneBook::record_t recordToAdd);
  void show(const std::string &markName, std::ostream &output) const;
  void store(const std::string &markName, const std::string &newMarkName, std::ostream &output);
  void deleteMark(const std::string &markName, std::ostream &output);

  void moveToFirstOrLast(const std::string &markName, step_t step, std::ostream &output);
  void moveOnSteps(const std::string &markName, int steps, std::ostream &output);

  void insertBefore(const std::string &markName, PhoneBook::record_t recordToAdd, std::ostream &output);
  void insertAfter(const std::string &markName, PhoneBook::record_t recordToAdd, std::ostream &output);
private:
  PhoneBook phoneBook;
  std::unordered_map<std::string, PhoneBook::iterator> marks_;

  void fixMarks();
  void printInvalidBookmark(std::ostream &output) const;
  void printEmpty(std::ostream &output) const;
};

#endif
