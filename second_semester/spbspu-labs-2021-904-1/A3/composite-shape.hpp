#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>

#include "shape.hpp"

namespace lukyanov
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape &object);
    CompositeShape(CompositeShape &&object) noexcept;
    ~CompositeShape() = default;
    CompositeShape &operator=(const CompositeShape &object);
    CompositeShape &operator=(CompositeShape &&object) noexcept;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    size_t getSize() const;
    void move(const point_t &newPosition) override;
    void move(double dx, double dy) override;
    void print(std::ostream &output) const override;
    void scale(double coefficient) override;
    void add(const std::shared_ptr<Shape> &object);
    void remove(size_t itemPosition);
    std::shared_ptr<Shape> operator[](size_t index);
  private:
    size_t size_;
    std::unique_ptr<std::shared_ptr<Shape>[]> shapes_;
  };
}

#endif
