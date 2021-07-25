#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <boost/test/unit_test.hpp>

#include "strategies.hpp"

BOOST_AUTO_TEST_SUITE(testStrategies)

  std::vector<int> testVector({1, 2, 3, 4, 5});

  BOOST_AUTO_TEST_CASE(indexAccessTest)
  {
    using iterator = typename IndexAccess<std::vector<int>>::iterator;
    iterator begin = IndexAccess<std::vector<int>>::begin(testVector);
    iterator end = IndexAccess<std::vector<int>>::end(testVector);
    BOOST_CHECK(begin == 0);
    BOOST_CHECK(end == testVector.size());
    for (size_t i = 0; i < testVector.size(); i++)
    {
      BOOST_CHECK(IndexAccess<std::vector<int>>::get(testVector, i) == testVector[i]);
    }
  }

  BOOST_AUTO_TEST_CASE(atAccessTest)
  {
    using iterator = typename AtAccess<std::vector<int>>::iterator;
    iterator begin = AtAccess<std::vector<int>>::begin(testVector);
    iterator end = AtAccess<std::vector<int>>::end(testVector);
    BOOST_CHECK(begin == 0);
    BOOST_CHECK(end == testVector.size());
    for (size_t i = 0; i < testVector.size(); i++)
    {
      BOOST_CHECK(AtAccess<std::vector<int>>::get(testVector, i) == testVector.at(i));
    }
  }

  BOOST_AUTO_TEST_CASE(accessWithIteratorsTest)
  {
    using iterator = typename AccessWithIterators<std::vector<int>>::iterator;
    iterator begin = AccessWithIterators<std::vector<int>>::begin(testVector);
    iterator end = AccessWithIterators<std::vector<int>>::end(testVector);
    BOOST_CHECK(begin == testVector.begin());
    BOOST_CHECK(end == testVector.end());
    for (iterator i = begin; i != end; i++)
    {
      BOOST_CHECK(AccessWithIterators<std::vector<int>>::get(testVector, i) == *i);
    }
  }

BOOST_AUTO_TEST_SUITE_END()
