#include "NamedSquare.h"

    //CONSTRUCTORS
    NamedSquare::NamedSquare(Point c, double s, std::string n):
    Rectangle(c, s, s), _name(n) {}

    NamedSquare::NamedSquare(const NamedSquare & source):
    Rectangle(source.Rectangle::get_center(), source.get_side(),
    source.get_side()), _name(source._name) {}

    //CONST MEMBERS
    double NamedSquare::get_side() const{
        return Rectangle::get_length();
    }
    std::string NamedSquare::get_name() const{
        return _name;
    }
    // pre-condition: none
    // post-condition: returns the name of this NamedSquare

    //MUTATORS
    void NamedSquare::set_side(double s){
        Rectangle::set_length(s);
        Rectangle::set_width(s);
    }
    // pre-condition: s is nonnegative
    // post-condition: s is the new side of this NamedSquare
    void NamedSquare::set_name(std::string n){
        _name = n;
    }
    // pre-condition: none
    // post-condition: n is the new name of this NamedSquare


std::ostream & operator << (std::ostream & os, NamedSquare ns){
 os << "(" <<ns.get_lower_left()<< ","<<ns.get_upper_right()<<","<<ns.get_name()<<")";
 return os;
}
// pre-condition: none
// post-condition: NamedSquare ns is output to stream os in the following
// format: [(lower left), (upper right), name]

std::istream & operator >> (std::istream & is, NamedSquare & ns){
    Point center;
    double side;
    std::string name;
    is>>center>>side>>name;
    ns.set_center(center);
    ns.set_side(side);
    ns.set_name(name);
    return is;
}
// pre-condition: none
// post-condition: a new value of NamedSquare ns is read from stream is in
// the following format: center side name
