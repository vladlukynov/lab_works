#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <boost/test/unit_test.hpp>

#include "functions.hpp"

BOOST_AUTO_TEST_SUITE(testFunctions)

  const char *correctAscending("ascending");
  const char *correctDescending("descending");
  const char *incorrectTypeOfSort("incorrectTypeOfSort");
  const char *emptyTypeOfSort = nullptr;

  std::vector<int> inputData({-5, 1, 7, 10, 40, 532, 18, -80, 95});
  const std::vector<int> outputAscendingData({-80, -5, 1, 7, 10, 18, 40, 95, 532});
  const std::vector<int> outputDescendingData({532, 95, 40, 18, 10, 7, 1, -5, -80});

  BOOST_AUTO_TEST_CASE(getTypeOfSortCorrectTest)
  {
    const sort_t ASCENDING = getTypeOfSort(correctAscending);
    const sort_t DESCENDING = getTypeOfSort(correctDescending);
    BOOST_CHECK(ASCENDING == ascending);
    BOOST_CHECK(DESCENDING == descending);
  }

  BOOST_AUTO_TEST_CASE(getTypeOfSortIncorrectTest)
  {
    BOOST_CHECK_THROW(getTypeOfSort(incorrectTypeOfSort), std::invalid_argument);
    BOOST_CHECK_THROW(getTypeOfSort(emptyTypeOfSort), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(ascendingSortCorrectTest)
  {
    sort<IndexAccess>(inputData, getTypeOfSort(correctAscending));
    BOOST_CHECK(inputData == outputAscendingData);
  }


  BOOST_AUTO_TEST_CASE(descendingSortCorrectTest)
  {
    sort<IndexAccess>(inputData, getTypeOfSort(correctDescending));
    BOOST_CHECK(inputData == outputDescendingData);
  }

BOOST_AUTO_TEST_SUITE_END()
