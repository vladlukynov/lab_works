#include "composite-shape.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "base-types.hpp"

lukyanov::CompositeShape::CompositeShape() :
  size_(0)
{};

lukyanov::CompositeShape::CompositeShape(const CompositeShape &object) :
  size_(object.size_)
{
  if (object.size_ > 0)
  {
    shapes_ = std::make_unique<std::shared_ptr<Shape>[]>(size_);
    for (size_t i = 0; i < size_; i++)
    {
      shapes_[i] = object.shapes_[i];
    }
  }
}

lukyanov::CompositeShape::CompositeShape(CompositeShape &&object) noexcept:
  size_(object.size_),
  shapes_(std::move(object.shapes_))
{
  object.size_ = 0;
}

lukyanov::CompositeShape &lukyanov::CompositeShape::operator=(const lukyanov::CompositeShape &object)
{
  if (this == &object)
  {
    return *this;
  }
  if (object.size_ > 0)
  {
    shapes_ = std::make_unique<std::shared_ptr<Shape>[]>(object.size_);
    for (size_t i = 0; i < object.size_; i++)
    {
      shapes_[i] = object.shapes_[i];
    }
  }
  else
  {
    shapes_ = nullptr;
  }
  size_ = object.size_;
  return *this;
}

lukyanov::CompositeShape &lukyanov::CompositeShape::operator=(lukyanov::CompositeShape &&object) noexcept
{
  size_ = object.size_;
  object.size_ = 0;
  shapes_ = std::move(object.shapes_);
  return *this;
}

double lukyanov::CompositeShape::getArea() const
{
  if (size_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }
  double tempArea = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    tempArea += shapes_[i]->getArea();
  }
  return tempArea;
}

lukyanov::rectangle_t lukyanov::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }
  double minX = shapes_[0]->getFrameRect().pos.x - shapes_[0]->getFrameRect().width / 2;
  double maxX = shapes_[0]->getFrameRect().pos.x + shapes_[0]->getFrameRect().width / 2;
  double minY = shapes_[0]->getFrameRect().pos.y - shapes_[0]->getFrameRect().height / 2;
  double maxY = shapes_[0]->getFrameRect().pos.y + shapes_[0]->getFrameRect().height / 2;
  for (size_t i = 1; i < size_; i++)
  {
    minX = std::min(minX, shapes_[i]->getFrameRect().pos.x - shapes_[i]->getFrameRect().width / 2);
    maxX = std::max(maxX, shapes_[i]->getFrameRect().pos.x + shapes_[i]->getFrameRect().width / 2);
    minY = std::min(minY, shapes_[i]->getFrameRect().pos.y - shapes_[i]->getFrameRect().height / 2);
    maxY = std::max(maxY, shapes_[i]->getFrameRect().pos.y + shapes_[i]->getFrameRect().height / 2);
  }
  const point_t tempPos({(maxX + minX) / 2, (maxY + minY) / 2});
  return {maxX - minX, maxY - minY, tempPos};
}

size_t lukyanov::CompositeShape::getSize() const
{
  return size_;
}

void lukyanov::CompositeShape::move(const point_t &newPosition)
{
  if (size_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }
  const double dx = newPosition.x - getFrameRect().pos.x;
  const double dy = newPosition.y - getFrameRect().pos.y;
  move(dx, dy);
}

void lukyanov::CompositeShape::move(double dx, double dy)
{
  if (size_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void lukyanov::CompositeShape::print(std::ostream &output) const
{
  if (size_ == 0)
  {
    output << "Composite shape is empty";
  }
  else
  {
    output << "Size: " << size_
           << "\nComposite shape consists of:\n";
    for (size_t i = 0; i < size_; i++)
    {
      shapes_[i]->print(output);
    }
  }
}

void lukyanov::CompositeShape::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Scale error. Coefficient is less than 0");
  }
  if (size_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }
  const rectangle_t tempRect = getFrameRect();
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->scale(coefficient);
    double newX = tempRect.pos.x + (shapes_[i]->getFrameRect().pos.x - tempRect.pos.x) * coefficient;
    double newY = tempRect.pos.y + (shapes_[i]->getFrameRect().pos.y - tempRect.pos.y) * coefficient;
    shapes_[i]->move({newX, newY});
  }
}

void lukyanov::CompositeShape::add(const std::shared_ptr<Shape> &object)
{
  if (object == nullptr)
  {
    throw std::logic_error("Trying to add an empty shape");
  }
  if (object.get() == this)
  {
    throw std::logic_error("Trying to add a composite shape to itself");
  }
  for (size_t i = 0; i < size_; i++)
  {
    if (shapes_[i] == object)
    {
      throw std::logic_error("Composite shape already contains this shape");
    }
  }
  std::unique_ptr<std::shared_ptr<Shape>[]> tempArray(std::make_unique<std::shared_ptr<Shape>[]>(size_ + 1));
  for (size_t i = 0; i < size_; i++)
  {
    tempArray[i] = std::move(shapes_[i]);
  }
  tempArray[size_] = object;
  size_++;
  shapes_ = std::move(tempArray);
};

void lukyanov::CompositeShape::remove(size_t shapePosition)
{
  if (size_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }
  if (size_ <= shapePosition)
  {
    throw std::out_of_range("Delete error. Array out of range");
  }
  std::unique_ptr<std::shared_ptr<Shape>[]> tempArray(std::make_unique<std::shared_ptr<Shape>[]>(size_ - 1));
  for (size_t i = 0; i < size_; i++)
  {
    if (i < shapePosition)
    {
      tempArray[i] = std::move(shapes_[i]);
    }
    else if (i > shapePosition)
    {
      tempArray[i - 1] = std::move(shapes_[i]);
    }
  }
  size_--;
  shapes_ = std::move(tempArray);
}

std::shared_ptr<lukyanov::Shape> lukyanov::CompositeShape::operator[](size_t index)
{
  if (size_ <= index)
  {
    throw std::out_of_range("Error. Array out of range");
  }
  return shapes_[index];
}
