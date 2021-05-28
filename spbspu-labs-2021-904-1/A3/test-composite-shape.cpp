#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <boost/test/unit_test.hpp>

#include "circle.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testCompositeShape)
  const double EPSILON = 0.0001;
  const double TEST_RADIUS = 3.0;
  const double TEST_WIDTH = 5.0;
  const double TEST_HEIGHT = 2.0;
  const lukyanov::point_t TEST_POS_CIRCLE({3.0, 4.0});
  const lukyanov::point_t TEST_POS_RECTANGLE({-1.0, -3.0});

  struct fixture
  {
    lukyanov::CompositeShape COMPSHAPE;
    fixture()
    {
      std::shared_ptr<lukyanov::Shape> TEST_RECTANGLE(std::make_shared<lukyanov::Rectangle>(TEST_WIDTH,
          TEST_HEIGHT, TEST_POS_RECTANGLE));
      std::shared_ptr<lukyanov::Shape> TEST_CIRCLE(std::make_shared<lukyanov::Circle>(TEST_RADIUS,
          TEST_POS_CIRCLE));
      COMPSHAPE.add(TEST_RECTANGLE);
      COMPSHAPE.add(TEST_CIRCLE);
    }
  };

  BOOST_AUTO_TEST_CASE(testEmptyCompositeShape)
  {
    const double EMPTY_SIZE = 0;
    lukyanov::CompositeShape TEST_SHAPE;
    BOOST_CHECK_THROW(TEST_SHAPE.getArea(), std::logic_error);
    BOOST_CHECK_CLOSE(TEST_SHAPE.getSize(), EMPTY_SIZE, EPSILON);
    BOOST_CHECK_THROW(TEST_SHAPE.getFrameRect(), std::logic_error);
    BOOST_CHECK_THROW(TEST_SHAPE.move(1.0, 2.0), std::logic_error);
    BOOST_CHECK_THROW(TEST_SHAPE.move({1.0, 2.0}), std::logic_error);
    BOOST_CHECK_THROW(TEST_SHAPE.scale(2.0), std::logic_error);
    BOOST_CHECK_THROW(TEST_SHAPE.remove(1), std::logic_error);
  }

  BOOST_FIXTURE_TEST_CASE(testCopyConstructor, fixture)
  {
    const lukyanov::CompositeShape COPYSHAPE(COMPSHAPE);
    const double SIZE = COPYSHAPE.getSize();
    BOOST_CHECK_CLOSE(COMPSHAPE.getArea(), COPYSHAPE.getArea(), EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getSize(), SIZE, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.x, COPYSHAPE.getFrameRect().pos.x, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.y, COPYSHAPE.getFrameRect().pos.y, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().width, COPYSHAPE.getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().height, COPYSHAPE.getFrameRect().height, EPSILON);
  }

  BOOST_FIXTURE_TEST_CASE(testCopyOperator, fixture)
  {
    const lukyanov::CompositeShape COPYSHAPE = COMPSHAPE;
    const double SIZE = COPYSHAPE.getSize();
    BOOST_CHECK_CLOSE(COMPSHAPE.getArea(), COPYSHAPE.getArea(), EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getSize(), SIZE, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.x, COPYSHAPE.getFrameRect().pos.x, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.y, COPYSHAPE.getFrameRect().pos.y, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().width, COPYSHAPE.getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().height, COPYSHAPE.getFrameRect().height, EPSILON);
  }

  BOOST_FIXTURE_TEST_CASE(testMoveConstructor, fixture)
  {
    const double AREA = COMPSHAPE.getArea();
    const double WIDTH = COMPSHAPE.getFrameRect().width;
    const double HEIGHT = COMPSHAPE.getFrameRect().height;
    const double SIZE = COMPSHAPE.getSize();
    const lukyanov::point_t POS = COMPSHAPE.getFrameRect().pos;
    const lukyanov::CompositeShape MOVESHAPE(std::move(COMPSHAPE));
    BOOST_CHECK_CLOSE(MOVESHAPE.getArea(), AREA, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getSize(), SIZE, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getFrameRect().pos.x, POS.x, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getFrameRect().pos.y, POS.y, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getFrameRect().width, WIDTH, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getFrameRect().height, HEIGHT, EPSILON);

    const double EMPTY_SIZE = 0;
    BOOST_CHECK_THROW(COMPSHAPE.getArea(), std::logic_error);
    BOOST_CHECK_CLOSE(COMPSHAPE.getSize(), EMPTY_SIZE, EPSILON);
    BOOST_CHECK_THROW(COMPSHAPE.getFrameRect(), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPE.move(1.0, 2.0), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPE.move({1.0, 2.0}), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPE.scale(2.0), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPE.remove(1), std::logic_error);
  }

  BOOST_FIXTURE_TEST_CASE(testMoveOperator, fixture)
  {
    const double AREA = COMPSHAPE.getArea();
    const double WIDTH = COMPSHAPE.getFrameRect().width;
    const double HEIGHT = COMPSHAPE.getFrameRect().height;
    const double SIZE = COMPSHAPE.getSize();
    const lukyanov::point_t POS = COMPSHAPE.getFrameRect().pos;
    const lukyanov::CompositeShape MOVESHAPE = std::move(COMPSHAPE);
    BOOST_CHECK_CLOSE(MOVESHAPE.getArea(), AREA, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getSize(), SIZE, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getFrameRect().pos.x, POS.x, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getFrameRect().pos.y, POS.y, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getFrameRect().width, WIDTH, EPSILON);
    BOOST_CHECK_CLOSE(MOVESHAPE.getFrameRect().height, HEIGHT, EPSILON);

    const double EMPTY_SIZE = 0;
    BOOST_CHECK_THROW(COMPSHAPE.getArea(), std::logic_error);
    BOOST_CHECK_CLOSE(COMPSHAPE.getSize(), EMPTY_SIZE, EPSILON);
    BOOST_CHECK_THROW(COMPSHAPE.getFrameRect(), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPE.move(1.0, 2.0), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPE.move({1.0, 2.0}), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPE.scale(2.0), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPE.remove(1), std::logic_error);
  }

  BOOST_FIXTURE_TEST_CASE(testMoveDxDy, fixture)
  {
    const double AREA = COMPSHAPE.getArea();
    const double WIDTH = COMPSHAPE.getFrameRect().width;
    const double HEIGHT = COMPSHAPE.getFrameRect().height;
    const double SIZE = COMPSHAPE.getSize();
    const lukyanov::point_t POS = COMPSHAPE.getFrameRect().pos;
    const double DX = 2.0, DY = 3.0;
    COMPSHAPE.move(DX, DY);
    BOOST_CHECK_CLOSE(COMPSHAPE.getArea(), AREA, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getSize(), SIZE, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.x, POS.x + DX, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.y, POS.y + DY, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().width, WIDTH, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().height, HEIGHT, EPSILON);
  }

  BOOST_FIXTURE_TEST_CASE(testMovePoint, fixture)
  {
    const double AREA = COMPSHAPE.getArea();
    const double WIDTH = COMPSHAPE.getFrameRect().width;
    const double HEIGHT = COMPSHAPE.getFrameRect().height;
    const double SIZE = COMPSHAPE.getSize();
    const lukyanov::point_t NEW_POS({1.0, 1.0});
    COMPSHAPE.move(NEW_POS);
    BOOST_CHECK_CLOSE(COMPSHAPE.getArea(), AREA, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getSize(), SIZE, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.x, NEW_POS.x, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.y, NEW_POS.y, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().width, WIDTH, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().height, HEIGHT, EPSILON);
  }

  BOOST_FIXTURE_TEST_CASE(testScaling, fixture)
  {
    const double AREA = COMPSHAPE.getArea();
    const double WIDTH = COMPSHAPE.getFrameRect().width;
    const double HEIGHT = COMPSHAPE.getFrameRect().height;
    const double SIZE = COMPSHAPE.getSize();
    const lukyanov::point_t POS = COMPSHAPE.getFrameRect().pos;
    const double COEFFICIENT = 3.0;
    COMPSHAPE.scale(COEFFICIENT);
    BOOST_CHECK_CLOSE(COMPSHAPE.getArea(), AREA * COEFFICIENT * COEFFICIENT, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getSize(), SIZE, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.x, POS.x, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.y, POS.y, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().width, WIDTH * COEFFICIENT, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().height, HEIGHT * COEFFICIENT, EPSILON);

    const lukyanov::point_t TEST_SCALED_POS_RECT({POS.x + (TEST_POS_RECTANGLE.x - POS.x) * COEFFICIENT,
        POS.y + (TEST_POS_RECTANGLE.y - POS.y) * COEFFICIENT});
    const lukyanov::point_t TEST_SCALED_POS_CIRCLE({POS.x + (TEST_POS_CIRCLE.x - POS.x) * COEFFICIENT,
        POS.y + (TEST_POS_CIRCLE.y - POS.y) * COEFFICIENT});
    BOOST_CHECK_CLOSE(COMPSHAPE[0]->getFrameRect().pos.x, TEST_SCALED_POS_RECT.x, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE[0]->getFrameRect().pos.y, TEST_SCALED_POS_RECT.y, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE[1]->getFrameRect().pos.x, TEST_SCALED_POS_CIRCLE.x, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE[1]->getFrameRect().pos.y, TEST_SCALED_POS_CIRCLE.y, EPSILON);
  }

  BOOST_FIXTURE_TEST_CASE(testIncorrectIndexOperator, fixture)
  {
    BOOST_CHECK_THROW(COMPSHAPE[2], std::out_of_range);
    lukyanov::CompositeShape EMPTYSHAPE;
    BOOST_CHECK_THROW(EMPTYSHAPE[0], std::logic_error);
  }

  BOOST_FIXTURE_TEST_CASE(testIncorrectRemove, fixture)
  {
    BOOST_CHECK_THROW(COMPSHAPE.remove(3), std::out_of_range);
  }

  BOOST_FIXTURE_TEST_CASE(testIncorrectData, fixture)
  {
    BOOST_CHECK_THROW(COMPSHAPE.scale(0.0), std::invalid_argument);
    BOOST_CHECK_THROW(COMPSHAPE.scale(-200.0), std::invalid_argument);

    std::shared_ptr<lukyanov::CompositeShape> COMPSHAPEPTR(std::make_shared<lukyanov::CompositeShape>(COMPSHAPE));
    BOOST_CHECK_THROW(COMPSHAPEPTR->add(COMPSHAPEPTR), std::logic_error);
    BOOST_CHECK_THROW(COMPSHAPEPTR->add(nullptr), std::logic_error);

    lukyanov::Rectangle TEST_RECT(1.0, 1.0, {1.0, 1.0});
    std::shared_ptr<lukyanov::Shape> TEST_RECT_PTR(std::make_shared<lukyanov::Rectangle>(TEST_RECT));
    COMPSHAPE.add(TEST_RECT_PTR);
    BOOST_CHECK_THROW(COMPSHAPE.add(TEST_RECT_PTR), std::logic_error);
  }

  BOOST_FIXTURE_TEST_CASE(testGetMethods, fixture)
  {
    const double RECT_AREA = TEST_WIDTH * TEST_HEIGHT;
    const double CIRCLE_AREA = M_PI * TEST_RADIUS * TEST_RADIUS;
    const double TEST_AREA = RECT_AREA + CIRCLE_AREA;
    const double TEST_SIZE = 2.0;

    double minX = TEST_POS_RECTANGLE.x - TEST_WIDTH / 2;
    double maxX = TEST_POS_RECTANGLE.x + TEST_WIDTH / 2;
    double minY = TEST_POS_RECTANGLE.y - TEST_HEIGHT / 2;
    double maxY = TEST_POS_RECTANGLE.y + TEST_HEIGHT / 2;
    minX = std::min(minX, TEST_POS_CIRCLE.x - TEST_RADIUS);
    maxX = std::max(maxX, TEST_POS_CIRCLE.x + TEST_RADIUS);
    minY = std::min(minY, TEST_POS_CIRCLE.y - TEST_RADIUS);
    maxY = std::max(maxY, TEST_POS_CIRCLE.y + TEST_RADIUS);
    const lukyanov::point_t TEST_POS({(maxX + minX) / 2, (maxY + minY) / 2});
    const double TEST_GET_WIDTH = maxX - minX;
    const double TEST_GET_HEIGHT = maxY - minY;

    BOOST_CHECK_CLOSE(COMPSHAPE.getArea(), TEST_AREA, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().height, TEST_GET_HEIGHT, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().width, TEST_GET_WIDTH, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.x, TEST_POS.x, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getFrameRect().pos.y, TEST_POS.y, EPSILON);
    BOOST_CHECK_CLOSE(COMPSHAPE.getSize(), TEST_SIZE, EPSILON);
  }

BOOST_AUTO_TEST_SUITE_END()
