#ifndef NAMEDSQUARE_H
#define NAMEDSQUARE_H

#include "rectangle.h"

class NamedSquare: public Rectangle
{
public:
    //CONSTRUCTORS
    NamedSquare(Point c = Point(), double s = double(), std::string n = std::string());
    // pre-condition: s is nonnegative
    // post-condition: creates new NamedSquare centered at c with side s and
    // name n (this is the default constructor)

     NamedSquare(const NamedSquare & source);
    // pre-condition: none
    // post-condition: creates a new NamedSquare that is a copy of the given
    // NamedSquare source (this is the copy constructor)
    // NOTE: the parameter MUST be passed as specified (constant reference)
    // to avoid infinite recursion

    //CONST MEMBERS
    double get_side() const;
    // pre-condition: none
    // post-condition: returns the side of this NamedSquare

    std::string get_name() const;
    // pre-condition: none
    // post-condition: returns the name of this NamedSquare

    //MUTATORS
    void set_side(double s);
    // pre-condition: s is nonnegative
    // post-condition: s is the new side of this NamedSquare

    void set_name(std::string n);
    // pre-condition: none
    // post-condition: n is the new name of this NamedSquare

    double get_length() const = delete;
    double get_width() const = delete;
    void set_length(double) = delete;
    void set_width(double) = delete;
    // the above member functions inherited from Rectangle are deleted
    // they are replaced by get_side() and set_side()
    // NOTE: get_center(), get_area(), get_perimeter(), get_lower_left(),
    // get_upper_right(), set_center() are still available but they must be
    // preceded by Rectangle:: (i.e., Rectangle::get_center(), etc.) if used in
    // a member function of NamedSquare
private:
    std::string _name;
    // INVARIANTS: _name is the name of this NamedSquare
    //
    // NOTE: private variables of Rectangle are NOT accessible to NamedSquare member
    // functions.
    // To retrieve their values, use Rectangle::get_center(), ...
    // To set their values, use Rectangle::set_center(c) or the constructors
    // Rectangle(c, l, w) or Rectangle(ll, ur)
};

std::ostream & operator << (std::ostream & os, NamedSquare ns);
// pre-condition: none
// post-condition: NamedSquare ns is output to stream os in the following
// format: [(lower left), (upper right), name]

std::istream & operator >> (std::istream & is, NamedSquare & ns);
// pre-condition: none
// post-condition: a new value of NamedSquare ns is read from stream is in
// the following format: center side name

#endif // NAMESQAURE_H
