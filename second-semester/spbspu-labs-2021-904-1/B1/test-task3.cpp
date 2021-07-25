#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <boost/test/unit_test.hpp>

#include "tasks.hpp"

BOOST_AUTO_TEST_SUITE(task3Test)
  const std::string INPUT1("3 2 6 5 4 22 3 1 0");
  const std::string INPUT2("3 2 6 5 4 22 3 2 0");
  const std::string INPUT3("3 2 6 5 4 22 3 1 3 0");
  const std::string OUTPUT1("3 5 3 1 ");
  const std::string OUTPUT2("3 1 1 1 2 6 1 1 1 5 4 22 3 1 1 1 2 ");
  const std::string OUTPUT3("3 2 6 5 4 22 3 1 3 ");
  const std::string INCORRECT_INPUT1("3 2a 6 0");
  const std::string INCORRECT_INPUT2("1 2 3 4 5");

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

  BOOST_FIXTURE_TEST_CASE(correctInput1Test, fixture)
  {
    input.str(INPUT1);
    task3();
    const std::string out = output.str();
    BOOST_CHECK_EQUAL(out, OUTPUT1);
  }

  BOOST_FIXTURE_TEST_CASE(correctInput2Test, fixture)
  {
    input.str(INPUT2);
    task3();
    const std::string out = output.str();
    BOOST_CHECK_EQUAL(out, OUTPUT2);
  }

  BOOST_FIXTURE_TEST_CASE(correctInput3Test, fixture)
  {
    input.str(INPUT3);
    task3();
    const std::string out = output.str();
    BOOST_CHECK_EQUAL(out, OUTPUT3);
  }

  BOOST_FIXTURE_TEST_CASE(incorrectNumberInput, fixture)  //error
  {
    input.str(INCORRECT_INPUT1);
    BOOST_CHECK_THROW(task3(), std::runtime_error);
  }

  BOOST_FIXTURE_TEST_CASE(incorrectWithoutZeroInput, fixture)
  {
    input.str(INCORRECT_INPUT2);
    BOOST_CHECK_THROW(task3(), std::runtime_error);
  }

BOOST_AUTO_TEST_SUITE_END()
