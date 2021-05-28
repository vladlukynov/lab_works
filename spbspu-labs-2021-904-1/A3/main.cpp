#include <iostream>
#include <memory>
#include <stdexcept>

#include "circle.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"

int main()
{
  try
  {
    lukyanov::Shape *shape;
    lukyanov::Rectangle rectangle(2.48, 5.2, {2.5, -2.5});
    shape = &rectangle;
    shape->print(std::cout);
    std::cout << "Shape area: " << shape->getArea() << "\n\n";
    shape->scale(3.0);
    std::cout << "After scaling with coefficient 3.0:\n";
    shape->print(std::cout);
    std::cout << "Shape area: " << shape->getArea() << "\n\n";
  }
  catch (const std::invalid_argument &exception)
  {
    std::cerr << exception.what() << "\n";
    return 1;
  }
  try
  {
    lukyanov::Shape *shape;
    lukyanov::Circle circle(2.5, {2.5, 3.5});
    shape = &circle;
    shape->print(std::cout);
    std::cout << "Shape area: " << shape->getArea() << "\n\n";
    shape->scale(3.0);
    std::cout << "After scaling with coefficient 3.0:\n";
    shape->print(std::cout);
    std::cout << "Shape area: " << shape->getArea() << "\n\n";
  }
  catch (const std::invalid_argument &exception)
  {
    std::cerr << exception.what() << "\n";
    return 1;
  }
  try
  {
    std::shared_ptr<lukyanov::Shape> rect1(new lukyanov::Rectangle(1, 2, {3, 4}));
    std::shared_ptr<lukyanov::Shape> rect2(new lukyanov::Rectangle(5, 6, {7, 8}));
    lukyanov::CompositeShape compShape;
    compShape.add(rect1);
    compShape.add(rect2);
    compShape.print(std::cout);
    std::cout << "Composite Shape Area: " << compShape.getArea() << "\n\n";
    compShape.scale(3.0);
    std::cout << "After scaling with coefficient 3.0:\n";
    compShape.print(std::cout);
    std::cout << "Composite Shape Area: " << compShape.getArea() << "\n";
  }
  catch (const std::invalid_argument &exception)
  {
    std::cerr << exception.what() << "\n";
    return 1;
  }
  catch (const std::out_of_range &exception)
  {
    std::cerr << exception.what() << "\n";
    return 1;
  }
  catch (const std::logic_error &exception)
  {
    std::cerr << exception.what() << "\n";
    return 1;
  }
  return 0;
}
