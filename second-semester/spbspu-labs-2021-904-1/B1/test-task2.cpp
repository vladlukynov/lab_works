#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <boost/test/unit_test.hpp>

#include "tasks.hpp"

BOOST_AUTO_TEST_SUITE(task2Test)
  const char *FILE_NAME("file.txt");
  const char *INCORRECT_FILE_NAME("file");
  const std::string INPUT("TEST DATA IN FILE");
  const std::string OUTPUT("TEST DATA IN FILE");

  struct fixture
  {
    fixture() :
      cout(std::cout.rdbuf())
    {
      std::cout.rdbuf(output.rdbuf());
    }
    ~fixture()
    {
      std::cout.rdbuf(cout);
    }
    std::streambuf *cout;
    std::stringstream output;
  };

  BOOST_FIXTURE_TEST_CASE(correctTask2Test, fixture)
  {
    std::ofstream file(FILE_NAME);
    file << INPUT;
    file.close();
    task2(FILE_NAME);
    std::remove(FILE_NAME);
    const std::string out = output.str();
    BOOST_CHECK_EQUAL(out, OUTPUT);
  }

  BOOST_AUTO_TEST_CASE(incorrectFileName)
  {
    BOOST_CHECK_THROW(task2(INCORRECT_FILE_NAME), std::runtime_error);
  }

BOOST_AUTO_TEST_SUITE_END()
