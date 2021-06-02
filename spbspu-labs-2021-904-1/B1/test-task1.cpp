#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <boost/test/unit_test.hpp>

#include "tasks.hpp"

BOOST_AUTO_TEST_SUITE(task1Test)
  const std::string ASCENDING_INPUT("3 2 6 5 4 22 3 1 2 0");
  const std::string ASCENDING_OUTPUT("0 1 2 2 3 3 4 5 6 22 \n0 1 2 2 3 3 4 5 6 22 \n0 1 2 2 3 3 4 5 6 22 ");
  const std::string DESCENDING_INPUT("3 2 6 5 4 22 3 1 2 0");
  const std::string DESCENDING_OUTPUT("22 6 5 4 3 3 2 2 1 0 \n22 6 5 4 3 3 2 2 1 0 \n22 6 5 4 3 3 2 2 1 0 ");
  const std::string INCORRECT_INPUT("incorrect_input");
  const char *ASCENDING_TYPEOFSORT("ascending");
  const char *DESCENDING_TYPEOFSORT("descending");
  const char *INCORRECT_TYPEOFSORT("abc");

  struct fixture
  {
    fixture() :
      cin(std::cin.rdbuf()),
      cout(std::cout.rdbuf())
    {
      std::cin.rdbuf(input.rdbuf());
      std::cout.rdbuf(output.rdbuf());
    }
    ~fixture()
    {
      std::cin.rdbuf(cin);
      std::cout.rdbuf(cout);
    }
    std::streambuf *cin;
    std::streambuf *cout;
    std::stringstream input;
    std::stringstream output;
  };

  BOOST_FIXTURE_TEST_CASE(correctAscendingTest, fixture)
  {
    input.str(ASCENDING_INPUT);
    task1(getTypeOfSort(ASCENDING_TYPEOFSORT));
    const std::string out = output.str();
    BOOST_CHECK_EQUAL(out, ASCENDING_OUTPUT);
  }

  BOOST_FIXTURE_TEST_CASE(correctDescendingTest, fixture)
  {
    input.str(DESCENDING_INPUT);
    task1(getTypeOfSort(DESCENDING_TYPEOFSORT));
    const std::string out = output.str();
    BOOST_CHECK_EQUAL(out, DESCENDING_OUTPUT);
  }

  BOOST_FIXTURE_TEST_CASE(incorrectDataTask1, fixture)
  {
    BOOST_CHECK_THROW(task1(getTypeOfSort(INCORRECT_TYPEOFSORT)), std::invalid_argument);
    input.str(INCORRECT_INPUT);
    BOOST_CHECK_THROW(task1(getTypeOfSort(ASCENDING_TYPEOFSORT)), std::runtime_error);
  }

BOOST_AUTO_TEST_SUITE_END()
