#include <boost/test/unit_test.hpp>

#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(testShape)

  BOOST_AUTO_TEST_CASE(testCorrectShapeInput)
  {
    const std::string output1("5 (1;3) (23;3) (15;8) (7;4) (1;3) ");
    const std::string output2("4 (5;5) (7;5) (7;6) (5;6) ");
    const std::string output3("3 (-9189;4906) (5155;-528) (9402;9807) ");
    Shape shape1;
    Shape shape2;
    Shape shape3;
    std::istringstream input("5 ( 1;3)    ( 23;  3)  (15 ;8) ( 7 ;4)  ( 1 ;3)");
    input >> shape1;
    input.str("4 (5;5) (7;5) (7;6) (5;6)");
    input >> shape2;
    input.str("3  (-9189; 4906)(  5155  ;-528     )   (9402; 9807)");
    input >> shape3;
    std::ostringstream output;

    output << shape1;
    BOOST_CHECK_EQUAL(output.str(), output1);

    output.str("");
    output << shape2;
    BOOST_CHECK_EQUAL(output.str(), output2);

    output.str("");
    output << shape3;
    BOOST_CHECK_EQUAL(output.str(), output3);
  }

  BOOST_AUTO_TEST_CASE(testIncorrectShapeInput)
  {
    Shape shape;
    std::istringstream input("2 (5 5) (7;5)");
    input >> shape;
    BOOST_CHECK(!input.eof());

    input.clear();
    input.str("2 (5; 5) 7;5)");
    BOOST_CHECK(!input.eof());

    input.clear();
    input.str("2 (5; 5) (7;5) (1;3)");
    BOOST_CHECK(!input.eof());

    input.clear();
    input.str("2 (5; 5)");
    BOOST_CHECK(!input.eof());
  }

  BOOST_AUTO_TEST_CASE(testCorrectPointInput)
  {
    const std::string output1("(4;3)");
    const std::string output2("(2;1)");
    Point point1;
    Point point2;
    std::istringstream input("(4;3)");
    input >> point1;
    input.str("(   2  ;  1    )");
    input >> point2;
    std::ostringstream output;

    output << point1;
    BOOST_CHECK_EQUAL(output.str(), output1);

    output.str("");
    output << point2;
    BOOST_CHECK_EQUAL(output.str(), output2);
  }

  BOOST_AUTO_TEST_CASE(testIncorrectPointInput)
  {
    Shape shape;
    std::istringstream input("(2  5)");
    input >> shape;
    BOOST_CHECK(!input.eof());

    input.clear();
    input.str("(2; )");
    BOOST_CHECK(!input.eof());

    input.clear();
    input.str("( ; 5)");
    BOOST_CHECK(!input.eof());

    input.clear();
    input.str("2;5)");
    BOOST_CHECK(!input.eof());

    input.clear();
    input.str("2;5");
    BOOST_CHECK(!input.eof());
  }

BOOST_AUTO_TEST_SUITE_END()
