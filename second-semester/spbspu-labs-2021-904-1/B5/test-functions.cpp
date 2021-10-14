#include <boost/test/unit_test.hpp>
#include <iterator>

#include "functions.hpp"

BOOST_AUTO_TEST_SUITE(testFunctions)

  const Shape TRIANGLE = {{1, 2}, {3, 4}, {5, 6}};
  const Shape SQUARE = {{10, 10}, {10, 11}, {11, 11}, {11, 10}};
  const Shape RECTANGLE = {{5, 5}, {7, 5}, {7, 6}, {5, 6}};
  const Shape PENTAGON = {{1, 3}, {23, 3}, {15, 8}, {7, 4}, {1, 3}};
  const size_t VERTICES = 16;
  const size_t COUNT_TRIANGLE = 1;
  const size_t COUNT_SQUARE = 1;
  const size_t COUNT_RECTANGLE = 2;
  const std::string OUTPUT_WITH_PENTAGON = "3 (1;2) (3;4) (5;6) \n5 (1;3) (23;3) (15;8) (7;4) (1;3) \n";
  const std::string OUTPUT_WITHOUT_PENTAGON = "3 (1;2) (3;4) (5;6) \n";
  const std::vector<Point> POINT_VECTOR = {{1, 2}, {10, 10}, {5, 5}, {1, 3}};

  struct Fixture
  {
    Shapes shapes1;
    Shapes shapes2;
    Fixture()
    {
      shapes1.push_back(TRIANGLE);
      shapes1.push_back(SQUARE);
      shapes1.push_back(RECTANGLE);
      shapes1.push_back(PENTAGON);
      shapes2.push_back(TRIANGLE);
      shapes2.push_back(PENTAGON);
    }
  };

  BOOST_AUTO_TEST_CASE(testDetailsFunctions)
  {
    BOOST_CHECK(details::isTriangle(TRIANGLE));
    BOOST_CHECK(!details::isTriangle(SQUARE));
    BOOST_CHECK(!details::isTriangle(RECTANGLE));
    BOOST_CHECK(!details::isTriangle(PENTAGON));

    BOOST_CHECK(!details::isSquare(TRIANGLE));
    BOOST_CHECK(details::isSquare(SQUARE));
    BOOST_CHECK(!details::isSquare(RECTANGLE));
    BOOST_CHECK(!details::isSquare(PENTAGON));

    BOOST_CHECK(!details::isRectangle(TRIANGLE));
    BOOST_CHECK(details::isRectangle(SQUARE));
    BOOST_CHECK(details::isRectangle(RECTANGLE));
    BOOST_CHECK(!details::isRectangle(PENTAGON));

    BOOST_CHECK(!details::isPentagon(TRIANGLE));
    BOOST_CHECK(!details::isPentagon(SQUARE));
    BOOST_CHECK(!details::isPentagon(RECTANGLE));
    BOOST_CHECK(details::isPentagon(PENTAGON));
  }

  BOOST_FIXTURE_TEST_CASE(testCountVertices, Fixture)
  {
    const size_t vertices = countVertices(shapes1);
    BOOST_CHECK_EQUAL(vertices, VERTICES);
  }

  BOOST_FIXTURE_TEST_CASE(testCountShapes, Fixture)
  {
    BOOST_CHECK_EQUAL(countShapes(shapes1, details::TRIANGLE), COUNT_TRIANGLE);
    BOOST_CHECK_EQUAL(countShapes(shapes1, details::SQUARE), COUNT_SQUARE);
    BOOST_CHECK_EQUAL(countShapes(shapes1, details::RECTANGLE), COUNT_RECTANGLE);
  }

  BOOST_FIXTURE_TEST_CASE(testDeletePentagons, Fixture)
  {
    std::ostringstream output;
    std::copy(shapes2.begin(), shapes2.end(), std::ostream_iterator<Shape>(output, "\n"));
    BOOST_CHECK_EQUAL(output.str(), OUTPUT_WITH_PENTAGON);

    output.str("");
    deletePentagons(shapes2);
    std::copy(shapes2.begin(), shapes2.end(), std::ostream_iterator<Shape>(output, "\n"));
    BOOST_CHECK_EQUAL(output.str(), OUTPUT_WITHOUT_PENTAGON);
  }

  BOOST_FIXTURE_TEST_CASE(testGetPointVector, Fixture)
  {
    const std::vector<Point> pointVector = getPointVector(shapes1);
    for (size_t i = 0; i < pointVector.size(); i++)
    {
      BOOST_CHECK_EQUAL(pointVector[i].x, POINT_VECTOR[i].x);
      BOOST_CHECK_EQUAL(pointVector[i].y, POINT_VECTOR[i].y);
    }
  }

BOOST_AUTO_TEST_SUITE_END()
