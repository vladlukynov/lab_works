#include <algorithm>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include <iterator>

#include "shape.hpp"
#include "functions.hpp"

void executeFirstTask(std::istream &input, std::ostream &output);
void executeSecondTask(std::istream &input, std::ostream &output);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Incorrect number of arguments\n";
    return 1;
  }
  std::istringstream stream(argv[1]);
  int numberOfTask;
  stream >> numberOfTask;
  if (!stream.eof())
  {
    std::cerr << "Incorrect arguments input\n";
    return 1;
  }
  switch (numberOfTask)
  {
    case 1:
    {
      try
      {
        executeFirstTask(std::cin, std::cout);
        break;
      }
      catch (const std::runtime_error &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
      catch (const std::exception &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
    }
    case 2:
    {
      try
      {
        executeSecondTask(std::cin, std::cout);
        break;
      }
      catch (const std::runtime_error &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
      catch (const std::exception &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
    }
    default:
    {
      std::cerr << "Incorrect number of task\n";
      return 1;
    }
  }
  return 0;
}

void executeFirstTask(std::istream &input, std::ostream &output)
{
  std::unordered_set<std::string> words((std::istream_iterator<std::string>(input)), std::istream_iterator<std::string>());
  if (!input.eof())
  {
    throw std::runtime_error("Reading error");
  }
  std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(output, "\n"));
}

void executeSecondTask(std::istream &input, std::ostream &output)
{
  Shapes shapes((std::istream_iterator<Shape>(input)), std::istream_iterator<Shape>());
  if (!input.eof())
  {
    throw std::runtime_error("Reading error");
  }
  output << "Vertices: " << countVertices(shapes) << "\n"
         << "Triangles: " << countShapes(shapes, details::TRIANGLE) << "\n"
         << "Squares: " << countShapes(shapes, details::SQUARE) << "\n"
         << "Rectangles: " << countShapes(shapes, details::RECTANGLE) << "\n";
  deletePentagons(shapes);
  output << "Points: ";
  std::vector<Point> pointVector = getPointVector(shapes);
  std::copy(pointVector.begin(), pointVector.end(), std::ostream_iterator<Point>(output, " "));
  std::sort(shapes.begin(), shapes.end(), ShapeComparator());
  output << "\nShapes: \n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape>(output, "\n"));
}
