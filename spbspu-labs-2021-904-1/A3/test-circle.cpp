#include <cmath>
#include <stdexcept>
#include <boost/test/unit_test.hpp>

#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(testCircle)
  const double EPSILON = 0.0001;
  const double TEST_RADIUS = 3.04;
  const lukyanov::point_t TEST_POS({5.2, 3.4});
  const double TEST_AREA = M_PI * TEST_RADIUS * TEST_RADIUS;

  BOOST_AUTO_TEST_CASE(testCorrectData)
  {
    lukyanov::Circle TEST_CIRCLE(TEST_RADIUS, TEST_POS);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getArea(), TEST_AREA, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().pos.x, TEST_POS.x, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().pos.y, TEST_POS.y, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().height, TEST_RADIUS * 2, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().width, TEST_RADIUS * 2, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(testMoveDxDy)
  {
    const double DX = 2.54, DY = 3.09;
    lukyanov::Circle TEST_CIRCLE(TEST_RADIUS, TEST_POS);
    TEST_CIRCLE.move(DX, DY);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getArea(), TEST_AREA, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().pos.x, TEST_POS.x + DX, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().pos.y, TEST_POS.y + DY, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().height, TEST_RADIUS * 2, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().width, TEST_RADIUS * 2, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(testMovePoint)
  {
    const lukyanov::point_t NEW_POS({2.9, 3.4});
    lukyanov::Circle TEST_CIRCLE(TEST_RADIUS, TEST_POS);
    TEST_CIRCLE.move(NEW_POS);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getArea(), TEST_AREA, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().pos.x, NEW_POS.x, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().pos.y, NEW_POS.y, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().height, TEST_RADIUS * 2, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().width, TEST_RADIUS * 2, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(testScaling)
  {
    const double TEST_COEFFICIENT = 3.0;
    lukyanov::Circle TEST_CIRCLE(TEST_RADIUS, TEST_POS);
    TEST_CIRCLE.scale(TEST_COEFFICIENT);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getArea(), TEST_AREA * TEST_COEFFICIENT * TEST_COEFFICIENT, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().pos.x, TEST_POS.x, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().pos.y, TEST_POS.y, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().height, 2 * TEST_RADIUS * TEST_COEFFICIENT, EPSILON);
    BOOST_CHECK_CLOSE(TEST_CIRCLE.getFrameRect().width, 2 * TEST_RADIUS * TEST_COEFFICIENT, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(testIncorrectDataOnScaling)
  {
    const double TEST_COEFFICIENT1 = -3.0;
    const double TEST_COEFFICIENT2 = 0.0;
    lukyanov::Circle TEST_CIRCLE(TEST_RADIUS, TEST_POS);
    BOOST_CHECK_THROW(TEST_CIRCLE.scale(TEST_COEFFICIENT1), std::invalid_argument);
    BOOST_CHECK_THROW(TEST_CIRCLE.scale(TEST_COEFFICIENT2), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testIncorrectData)
  {
    BOOST_CHECK_THROW(lukyanov::Circle TEST_CIRCLE(0.0, TEST_POS), std::invalid_argument);
    BOOST_CHECK_THROW(lukyanov::Circle TEST_CIRCLE(-5.0, TEST_POS), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
