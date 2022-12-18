#include <iostream>

#include "Point.h"

std::ostream & operator << (std::ostream &out, const Point &p) {
  out << '(' << p.x << ", " << p.y << ')';
  return out;
}

std::istream & operator >> (std::istream &in,  Point &p) {
  in >> p.x >> p.y;
  return in;
}

Point Point::operator + (const Point &p) {
  return Point(this->getX() + p.getX(), this->getY() + p.getY());
}

Point& Point::operator += (const Point &p) {
  this->x += p.getX();
  this->y += p.getY();
  return *this;
}