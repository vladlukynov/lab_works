#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <boost/test/unit_test.hpp>

#include "functions.hpp"
#include "tasks.hpp"

BOOST_AUTO_TEST_SUITE(task4Test)
  const int SIZE = 10;
  const int INCORRECT_SIZE = -10;
  const char *ASCENDING_TYPEOFSORT = "ascending";
  const char *DESCENDING_TYPEOFSORT = "descending";
  const char *INCORRECT_TYPEOFSORT = "incorrect";

  BOOST_AUTO_TEST_CASE(testIncorrectInput)
  {
    BOOST_CHECK_THROW(task4(getTypeOfSort(INCORRECT_TYPEOFSORT), SIZE), std::invalid_argument);
    BOOST_CHECK_THROW(task4(getTypeOfSort(ASCENDING_TYPEOFSORT), INCORRECT_SIZE), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testAscendingSort)
  {
    sort_t SORT_T(getTypeOfSort(ASCENDING_TYPEOFSORT));
    std::vector<double> input(SIZE);
    fillRandom(input.data(), SIZE);
    sort<IndexAccess>(input, SORT_T);
    for (auto i = input.begin(); i != input.end() - 1; i++)
    {
      BOOST_CHECK(*i <= *(i + 1));
    }
  }

  BOOST_AUTO_TEST_CASE(testDescendingSort)
  {
    sort_t SORT_T(getTypeOfSort(DESCENDING_TYPEOFSORT));
    std::vector<double> input(SIZE);
    fillRandom(input.data(), SIZE);
    sort<IndexAccess>(input, SORT_T);
    for (auto i = input.begin(); i != input.end() - 1; i++)
    {
      BOOST_CHECK(*(i + 1) <= *i);
    }
  }

BOOST_AUTO_TEST_SUITE_END()
