#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"


  class Rectangle
  {
  public:

    // CONSTRUCTORS
    Rectangle(Point c = Point(), double l = double(), double w = double());
    // pre-condition: l, w >= 0.0
    // post-condition: creates a new Rectangle with center c, length l and width w
    //                 default value: center at origin, length and width 0

    Rectangle(Point lower_left, Point upper_right);
    // pre-condition: lower_left must be to the left and below upper_right, or
    //                they are the same point
    // post-condition: creates a new Rectangle with the given corners

    //CONST MEMBERS
    double get_length() const;
    // pre-condition: none
    // post-condition: returns the length of this Rectangle

    double get_width() const;
    // pre-condition: none
    // post-condition: returns the width of this Rectangle

    double get_area() const;
    // pre-condition: none
    // post-condition: returns the area of this Rectangle

    double get_perimeter() const;
    // pre-condition: none
    // post-condition: returns the perimeter of this Rectangle

    Point get_lower_left() const;
    // pre-condition: none
    // post-condition: returns the lower left corner of this Rectangle

    Point get_upper_right() const;
    // pre-condition: none
    // post-condition: returns the upper right corner of this Rectangle

    Point get_center() const;
    // pre-condition: none
    // post-condition: returns the center of this Rectangle

    //MUTATORS
    void set_length(double l);
    // pre-condition: l is nonnegative
    // post-condition: l is the new length of this Rectangle; its center and
    //                 width are unchanged

    void set_width(double w);
    // pre-condition: w is nonnegative
    // post-condition: w is the new width of this Rectangle; its center and length are unchanged

    void set_center(Point c);
    // pre-condition: none
    // post-condition: c is the new center of this Rectangle; its length and
    //                  width are unchanged

  private:
    Point _center;
    double _length;
    double _width;
    // INVARIANTS: _center, _length, _width are the center, length, and width
    //             of this Rectangle respectively

  };

  std::ostream & operator << (std::ostream & os, Rectangle r);
  // pre-condition: none
  // post-condition: Rectangle r is output to stream os in the following
  //                 format: [(lower left), (upper right)]

  std::istream & operator >> (std::istream & is, Rectangle & r);
  // pre-condition: none
  // post-condition: a new value of Rectangle r is read from stream is in the
  //                 following format: center length width

  Rectangle operator + (Rectangle a, Rectangle b);
  // pre-condition: none
  // post-condition: returns the smallest Rectangle containing both a and b

#endif // RECTANGLE_H#define RECTANGLE_H

//#endif // RECTANGLE_H
