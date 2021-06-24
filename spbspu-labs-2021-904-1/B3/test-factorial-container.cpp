#include <boost/test/unit_test.hpp>

#include "factorial-container.hpp"

BOOST_AUTO_TEST_SUITE(testFactorialContainer)

  const size_t size = 10;

  BOOST_AUTO_TEST_CASE(testOverflowConatiner)
  {
    const size_t overflowSize = 9999999;
    BOOST_CHECK_THROW(FactorialContainer container(overflowSize), std::overflow_error);
  }

  BOOST_AUTO_TEST_CASE(testIncrementOperation)
  {
    FactorialContainer container(size);
    auto iterator1 = container.begin();
    auto iterator2 = container.begin();

    size_t testValue = 1;
    for (size_t i = 2; i <= size; i++)
    {
      BOOST_CHECK(*(iterator1++) == testValue);
      testValue *= i;
    }

    testValue = 1;
    for (size_t i = 2; i <= size; i++)
    {
      testValue *= i;
      BOOST_CHECK(*(++iterator2) == testValue);
    }

    iterator1 = container.end();
    BOOST_CHECK_THROW(iterator1++, std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(testDecrementOperation)
  {
    FactorialContainer container(size);
    auto iterator1 = container.end();
    auto iterator2 = container.end();

    iterator1--;
    size_t testValue = calculateFactorialValue(size);
    for (size_t i = 10; i >= 2; i--)
    {
      BOOST_CHECK(*(iterator1--) == testValue);
      testValue /= i;
    }

    testValue = calculateFactorialValue(size);
    iterator2--;
    for (size_t i = 10; i >= 2; i--)
    {
      testValue /= i;
      BOOST_CHECK(*(--iterator2) == testValue);
    }

    iterator1 = container.begin();
    BOOST_CHECK_THROW(iterator1--, std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(testreferenceOperator)
  {
    size_t testValue = 1;
    FactorialContainer container(size);
    auto iterator = container.begin();
    for (size_t i = 2; i <= size; i++)
    {
      BOOST_CHECK_EQUAL(*iterator, testValue);
      iterator++;
      testValue *= i;
    }
  }

  BOOST_AUTO_TEST_CASE(testEmptyContainer)
  {
    FactorialContainer emptyFactorialContainer;
    BOOST_CHECK(emptyFactorialContainer.begin() == emptyFactorialContainer.end());
  }

BOOST_AUTO_TEST_SUITE_END()
