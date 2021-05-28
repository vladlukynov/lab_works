#include <stdexcept>
#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(rectangleTest)
  const double EPSILON = 0.0001;
  const double TEST_WIDTH = 5.3;
  const double TEST_HEIGHT = 4.2;
  const double TEST_AREA = TEST_WIDTH * TEST_HEIGHT;
  const lukyanov::point_t TEST_POS({2.0, 5.0});

  BOOST_AUTO_TEST_CASE(testCorrectData)
  {
    lukyanov::Rectangle TEST_RECTANGLE(TEST_WIDTH, TEST_HEIGHT, TEST_POS);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getArea(), TEST_AREA, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().width, TEST_WIDTH, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().height, TEST_HEIGHT, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().pos.x, TEST_POS.x, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().pos.y, TEST_POS.y, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(testMoveDxDy)
  {
    lukyanov::Rectangle TEST_RECTANGLE(TEST_WIDTH, TEST_HEIGHT, TEST_POS);
    const double DX = 5.02, DY = 6.21;
    TEST_RECTANGLE.move(DX, DY);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getArea(), TEST_AREA, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().width, TEST_WIDTH, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().height, TEST_HEIGHT, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().pos.x, TEST_POS.x + DX, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().pos.y, TEST_POS.y + DY, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(testMovePoint)
  {
    lukyanov::Rectangle TEST_RECTANGLE(TEST_WIDTH, TEST_HEIGHT, TEST_POS);
    const lukyanov::point_t NEW_POS({10.0, 10.0});
    TEST_RECTANGLE.move(NEW_POS);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getArea(), TEST_AREA, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().width, TEST_WIDTH, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().height, TEST_HEIGHT, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().pos.x, NEW_POS.x, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().pos.y, NEW_POS.y, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(testScaling)
  {
    lukyanov::Rectangle TEST_RECTANGLE(TEST_WIDTH, TEST_HEIGHT, TEST_POS);
    const double TEST_COEFFICIENT = 3.0;
    TEST_RECTANGLE.scale(TEST_COEFFICIENT);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getArea(), TEST_AREA * TEST_COEFFICIENT * TEST_COEFFICIENT, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().width, TEST_WIDTH * TEST_COEFFICIENT, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().height, TEST_HEIGHT * TEST_COEFFICIENT, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().pos.x, TEST_POS.x, EPSILON);
    BOOST_CHECK_CLOSE(TEST_RECTANGLE.getFrameRect().pos.y, TEST_POS.y, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(testIncorrectDataOnScaling)
  {
    lukyanov::Rectangle TEST_RECT(TEST_WIDTH, TEST_HEIGHT, TEST_POS);
    const double TEST_COEFFICIENT1 = -3.0;
    const double TEST_COEFFICIENT2 = 0.0;
    BOOST_CHECK_THROW(TEST_RECT.scale(TEST_COEFFICIENT1), std::invalid_argument);
    BOOST_CHECK_THROW(TEST_RECT.scale(TEST_COEFFICIENT2), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testIncorrectData)
  {
    BOOST_CHECK_THROW(lukyanov::Rectangle TEST_RECT(0.0, 0.0, TEST_POS), std::invalid_argument);
    BOOST_CHECK_THROW(lukyanov::Rectangle TEST_RECT(-5.0, 0.0, TEST_POS), std::invalid_argument);
    BOOST_CHECK_THROW(lukyanov::Rectangle TEST_RECT(0.0, -5.0, TEST_POS), std::invalid_argument);
    BOOST_CHECK_THROW(lukyanov::Rectangle TEST_RECT(-5.0, -5.0, TEST_POS), std::invalid_argument);
  }
BOOST_AUTO_TEST_SUITE_END()
