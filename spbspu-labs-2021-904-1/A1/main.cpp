#include <iostream>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

int main()
{
  Shape* shape;
  try
  {
    Rectangle rectangle(2.48, 5.2, { 2.5, -2.5 });
    shape = &rectangle;
    shape->print(std::cout);
    std::cout << "Shape area: " << shape->getArea() << "\n\n";
    shape->move({ 1, 1 });
    shape->print(std::cout);
    shape->move(1.5, 2.8);
    shape->print(std::cout);
  }
  catch (const std::invalid_argument& exception)
  {
    std::cerr << exception.what();
    return 1;
  }
  try
  {
    Circle circle(2.5, { 2.5, 3.5 });
    shape = &circle;
    shape->print(std::cout);
    std::cout << "Shape area: " << shape->getArea() << "\n\n";
    shape->move({ 1, 1 });
    shape->print(std::cout);
    shape->move(1.5, 2.8);
    shape->print(std::cout);
  }
  catch (const std::invalid_argument& exception)
  {
    std::cerr << exception.what();
    return 1;
  }
  return 0;
}
