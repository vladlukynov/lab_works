#include <boost/test/unit_test.hpp>
#include <string>

#include "data-struct.hpp"

BOOST_AUTO_TEST_SUITE(dataStructTests)

  struct Fixture
  {
    std::istringstream input;
    DataStruct dataStruct;
  };

  BOOST_FIXTURE_TEST_CASE(testCorrectInput, Fixture)
  {
    input.str("1, 2, string");
    input >> dataStruct;
    BOOST_CHECK(dataStruct.key1 == 1);
    BOOST_CHECK(dataStruct.key2 == 2);
    BOOST_CHECK(dataStruct.str == "string");
    BOOST_CHECK(input);
  }

  BOOST_FIXTURE_TEST_CASE(testIncorrectInput, Fixture)
  {
    input.str(", 1, string");
    input >> dataStruct;
    BOOST_CHECK(!input);
    input.clear();

    input.str("1, , string");
    input >> dataStruct;
    BOOST_CHECK(!input);
    input.clear();

    input.str("1, 1, ");
    input >> dataStruct;
    BOOST_CHECK(!input);
    input.clear();

    input.str("1 1, string");
    input >> dataStruct;
    BOOST_CHECK(!input);
    input.clear();

    input.str("1, 1 string");
    input >> dataStruct;
    BOOST_CHECK(!input);
    input.clear();

    input.str("1 1 string");
    input >> dataStruct;
    BOOST_CHECK(!input);
  }

  BOOST_FIXTURE_TEST_CASE(testIncorrectNumbersInput, Fixture)
  {
    input.str("6, 6, string");
    input >> dataStruct;
    BOOST_CHECK(!input);
    input.clear();

    input.str("6, 1, string");
    input >> dataStruct;
    BOOST_CHECK(!input);
    input.clear();

    input.str("1, 6, string");
    input >> dataStruct;
    BOOST_CHECK(!input);
  }

  BOOST_AUTO_TEST_CASE(testComparing)
  {
    CompareDataStructs compare;

    DataStruct dataStruct1 = {1, 1, "string"};
    DataStruct dataStruct2 = {2, 1, "string"};
    BOOST_CHECK(compare(dataStruct1, dataStruct2));

    dataStruct1 = {2, 1, "string"};
    dataStruct2 = {1, 1, "string"};
    BOOST_CHECK(!compare(dataStruct1, dataStruct2));

    dataStruct1 = {1, 1, "string"};
    dataStruct2 = {1, 2, "string"};
    BOOST_CHECK(compare(dataStruct1, dataStruct2));

    dataStruct1 = {1, 2, "string"};
    dataStruct2 = {1, 1, "string"};
    BOOST_CHECK(!compare(dataStruct1, dataStruct2));

    dataStruct1 = {1, 1, "string"};
    dataStruct2 = {1, 1, "longString"};
    BOOST_CHECK(compare(dataStruct1, dataStruct2));

    dataStruct1 = {1, 1, "longString"};
    dataStruct2 = {1, 1, "string"};
    BOOST_CHECK(!compare(dataStruct1, dataStruct2));
  }

BOOST_AUTO_TEST_SUITE_END()
