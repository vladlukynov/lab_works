#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>

#include "phonebook.hpp"

BOOST_AUTO_TEST_SUITE(phoneBook)

  const PhoneBook::record_t record1 = {"79616579999", "Vladislav Lukyanov"};
  const PhoneBook::record_t record2 = {"79999999999", "Vadim"};
  const PhoneBook::record_t record3 = {"77777777777", "Oleg"};

  struct fixture
  {
    fixture()
    {
      phoneBook.add(record1);
      phoneBook.add(record2);
    }

    PhoneBook phoneBook;
  };

  BOOST_FIXTURE_TEST_CASE(testBeginMethod, fixture)
  {
    BOOST_CHECK(record1.name == phoneBook.begin()->name);
    BOOST_CHECK(record1.number == phoneBook.begin()->number);
  }

  BOOST_FIXTURE_TEST_CASE(testEndMethod, fixture)
  {
    BOOST_CHECK(record2.name == std::prev(phoneBook.end())->name);
    BOOST_CHECK(record2.number == std::prev(phoneBook.end())->number);
  }

  BOOST_FIXTURE_TEST_CASE(testInsertAfterMethod, fixture)
  {
    auto iterator = phoneBook.begin();
    phoneBook.insertAfter(record3, iterator);
    iterator = std::next(iterator);
    BOOST_CHECK(iterator->number == record3.number);
    BOOST_CHECK(iterator->name == record3.name);
  }

  BOOST_FIXTURE_TEST_CASE(testInsertBeforeMethod, fixture)
  {
    auto iterator = std::prev(phoneBook.end());
    phoneBook.insertBefore(record3, iterator);
    iterator = std::prev(iterator);
    BOOST_CHECK(iterator->number == record3.number);
    BOOST_CHECK(iterator->name == record3.name);
  }

  BOOST_AUTO_TEST_CASE(testIsEmptyMethod)
  {
    PhoneBook emptyPhoneBook;
    BOOST_CHECK(emptyPhoneBook.isEmpty() == true);
    emptyPhoneBook.add(record1);
    BOOST_CHECK(emptyPhoneBook.isEmpty() == false);
  }

  BOOST_FIXTURE_TEST_CASE(testSizeMethod, fixture)
  {
    BOOST_CHECK(phoneBook.size() == 2);
  }

  BOOST_FIXTURE_TEST_CASE(testRemoveMethod, fixture)
  {
    phoneBook.deleteContact(phoneBook.begin());
    BOOST_CHECK(phoneBook.begin()->name == record2.name);
    BOOST_CHECK(phoneBook.begin()->number == record2.number);
  }

BOOST_AUTO_TEST_SUITE_END()
