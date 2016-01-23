#ifndef POINT_H
#define POINT_H

#include <iostream>

// SPECIFICATIONS of Point


  class Point
  {
  public:

    // CONSTRUCTORS

    // pre-condition: xval and yval are initial x and y coordinates
    //                of this Point (default values = 0.0)
    // post-condition: creates a new Point with given coordinates
    Point(double xval = double(), double yval = double());

    // CONST MEMBERS

    // pre-condition: none
    // post-condition: returns the x-coordinate of this Point
    double get_x() const;

    // pre-condition: none
    // post-condition: returns the y-coordinate of this Point
    double get_y() const;

    // MUTATORS

    // pre-condition: none
    // post-condition: sets the x-coordinate of this Point to nx
    void set_x(double nx);

    // pre-condition: none
    // post-condition: sets the y-coordinate of this Point to ny
    void set_y(double ny);

  private:
    // CLASS INVARIANTS:
    // x and y are the x- and y-coordinates of this Point
    double x, y;
  };

  // input/output operators
  std::ostream & operator << (std::ostream &, Point);
  std::istream & operator >> (std::istream &, Point &);

#endif // POINT_H
