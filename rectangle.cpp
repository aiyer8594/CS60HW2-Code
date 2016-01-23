#include "rectangle.h"
#include <cassert>
#include <algorithm>


    //CONSTRUCTORS
  Rectangle::Rectangle(Point c, double l, double w): _center(c), _length(l), _width(w)
  {}

  Rectangle::Rectangle(Point lower_left, Point upper_right)
  {
    double llx = lower_left.get_x();
    double lly = lower_left.get_y();
    double urx = upper_right.get_x();
    double ury = upper_right.get_y();

    assert(llx <= urx && lly <= ury);

    _center = Point((llx + urx)/2.0, (lly+ury)/2.0);
    _length = urx - llx;
    _width = ury - lly;
  }

  //CONST MEMBERS
  double Rectangle::get_length() const
  {
    return _length;
  }
  double Rectangle::get_width() const
  {
    return _width;
  }
  Point Rectangle::get_center() const
  {
    return _center;
  }
  Point Rectangle::get_lower_left() const
  {
    return Point(_center.get_x() - _length/2.0, _center.get_y() - _width/2.0);
  }
  Point Rectangle::get_upper_right() const
  {
    return Point(_center.get_x() + _length/2.0, _center.get_y() + _width/2.0);
  }
  double Rectangle::get_area() const
  {
    return _length * _width;
  }
  double Rectangle::get_perimeter() const
  {
    return 2.0*(_length + _width);
  }

  //MUTATORS
  void Rectangle::set_length(double l)
  {
    assert(l >= 0.0);
    _length = l;
  }
  void Rectangle::set_width(double w)
  {
    assert(w >= 0.0);
    _width = w;
  }
  void Rectangle::set_center(Point p)
  {
    _center = p;
  }

  std::ostream & operator << (std::ostream & os, Rectangle r)
  {
    os << "[" << r.get_lower_left() << ", " << r.get_upper_right() << "]";
    return os;
  }

  std::istream & operator >> (std::istream & is, Rectangle & r)
  {
    Point c;
    double l, w;

    is >> c >> l >> w;
    r = Rectangle (c, l, w);
    return is;

  }

  Rectangle operator +(Rectangle a, Rectangle b)
  {
    Point all = a.get_lower_left();
    Point aur = a.get_upper_right();
    Point bll = b.get_lower_left();
    Point bur = b.get_upper_right();

    Point ll = Point(std::min(all.get_x(), bll.get_x()),
                     std::min(all.get_y(), bll.get_y()));

    Point ur = Point(std::max(aur.get_x(), bur.get_x()),
                     std::max(aur.get_y(), bur.get_y()));

    return Rectangle(ll, ur);

  }
