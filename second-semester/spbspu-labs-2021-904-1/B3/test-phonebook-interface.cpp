#include <boost/test/unit_test.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "phonebook-interface.hpp"

BOOST_AUTO_TEST_SUITE(testPhoneBookInterface)

  const std::string markName("current");
  const std::string newMarkName("newMarkName");
  const std::string invalidMarkName("invalidMarkName");
  const PhoneBook::record_t record1 = {"79616579999", "Vladislav Lukyanov"};
  const PhoneBook::record_t record2 = {"79999999999", "Vadim"};
  const PhoneBook::record_t record3 = {"77777777777", "Oleg"};
  const std::string output1("79616579999 Vladislav Lukyanov\n");
  const std::string output2("79999999999 Vadim\n");
  const std::string output3("77777777777 Oleg\n");
  const std::string invalidBookMark("<INVALID BOOKMARK>\n");
  const std::string empty("<EMPTY>\n");

  struct fixture
  {
    fixture()
    {
      phoneBookInterface.add(record1);
      phoneBookInterface.add(record2);
    }
    PhoneBookInterface phoneBookInterface;
  };

  BOOST_FIXTURE_TEST_CASE(testShowMethod, fixture)
  {
    std::ostringstream output;
    phoneBookInterface.show(markName, output);
    BOOST_CHECK(output.str() == output1);
    output.str("");
    phoneBookInterface.show(invalidMarkName, output);
    BOOST_CHECK(output.str() == invalidBookMark);
  }

  BOOST_FIXTURE_TEST_CASE(testStoreMethod, fixture)
  {
    std::ostringstream output;
    phoneBookInterface.store(markName, newMarkName, output);
    phoneBookInterface.show(markName, output);
    BOOST_CHECK(output.str() == output1);
    output.str("");
    phoneBookInterface.show(newMarkName, output);
    BOOST_CHECK(output.str() == output1);
    output.str("");
    phoneBookInterface.store(invalidMarkName, newMarkName, output);
    BOOST_CHECK(output.str() == invalidBookMark);
  }

  BOOST_FIXTURE_TEST_CASE(testDeleteMarkMethod, fixture)
  {
    std::ostringstream output;
    PhoneBookInterface emptyPhoneBook;
    emptyPhoneBook.deleteMark(markName, output);
    BOOST_CHECK(output.str() == empty);
    output.str("");
    phoneBookInterface.deleteMark(invalidMarkName, output);
    BOOST_CHECK(output.str() == invalidBookMark);
    output.str("");
    phoneBookInterface.deleteMark(markName, output);
    phoneBookInterface.show(markName, output);
    BOOST_CHECK(output.str() == output2);
  }

  BOOST_FIXTURE_TEST_CASE(testMoveOnStepsMethod, fixture)
  {
    std::ostringstream output;
    PhoneBookInterface emptyPhoneBook;
    emptyPhoneBook.moveOnSteps(markName, 1, output);
    BOOST_CHECK(output.str() == empty);
    output.str("");
    phoneBookInterface.moveOnSteps(invalidMarkName, 1, output);
    BOOST_CHECK(output.str() == invalidBookMark);
    output.str("");
    phoneBookInterface.moveOnSteps(markName, 1, output);
    phoneBookInterface.show(markName, output);
    BOOST_CHECK(output.str() == output2);
  }

  BOOST_FIXTURE_TEST_CASE(testMoveToFirstOrLastMethod, fixture)
  {
    std::ostringstream output;
    PhoneBookInterface emptyPhoneBook;
    emptyPhoneBook.moveToFirstOrLast(markName, PhoneBookInterface::step_t::first, output);
    BOOST_CHECK(output.str() == empty);
    output.str("");
    phoneBookInterface.moveToFirstOrLast(invalidMarkName, PhoneBookInterface::step_t::first, output);
    BOOST_CHECK(output.str() == invalidBookMark);
    output.str("");
    phoneBookInterface.moveToFirstOrLast(markName, PhoneBookInterface::step_t::last, output);
    phoneBookInterface.show(markName, output);
    BOOST_CHECK(output.str() == output2);
    output.str("");
    phoneBookInterface.moveToFirstOrLast(markName, PhoneBookInterface::step_t::first, output);
    phoneBookInterface.show(markName, output);
    BOOST_CHECK(output.str() == output1);
  }

  BOOST_FIXTURE_TEST_CASE(testInsertBeforeMethod, fixture)
  {
    std::ostringstream output;
    phoneBookInterface.insertBefore(markName, record3, output);
    phoneBookInterface.moveToFirstOrLast(markName, PhoneBookInterface::step_t::first, output);
    phoneBookInterface.show(markName, output);
    BOOST_CHECK(output3 == output.str());
    output.str("");
    phoneBookInterface.insertBefore(invalidMarkName, record3, output);
    BOOST_CHECK(output.str() == invalidBookMark);
  }

  BOOST_FIXTURE_TEST_CASE(testInsertAfterMethod, fixture)
  {
    std::ostringstream output;
    phoneBookInterface.insertAfter(markName, record3, output);
    phoneBookInterface.moveOnSteps(markName, 1, output);
    phoneBookInterface.show(markName, output);
    BOOST_CHECK(output3 == output.str());
    output.str("");
    phoneBookInterface.insertAfter(invalidMarkName, record3, output);
    BOOST_CHECK(output.str() == invalidBookMark);
  }

BOOST_AUTO_TEST_SUITE_END()
