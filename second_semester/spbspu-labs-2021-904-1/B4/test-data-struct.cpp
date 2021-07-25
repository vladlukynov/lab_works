#include <boost/test/unit_test.hpp>
#include <string>
#include <sstream>

#include "data-struct.hpp"

BOOST_AUTO_TEST_SUITE(dataStructTests)

  const std::string str1 = "1,2,test";

  BOOST_AUTO_TEST_CASE(readKeyTest)
  {
    std::istringstream input(str1);
    const int key1 = readKey(input);
    input.get();
    const int key2 = readKey(input);
    BOOST_CHECK(key1 == 1);
    BOOST_CHECK(key2 == 2);
  }

BOOST_AUTO_TEST_SUITE_END()
