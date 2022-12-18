/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  const std::vector<Point>& poly1 = lhs;
  const std::vector<Point>& poly2 = rhs;

  for (const Point& p: poly2) {
    if (!lhs.contains(p)) {
      return false;
    }
  }
  for (const Point& p: poly1) {
    if (!rhs.contains(p)) {
      return false;
    }
  }
  return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {

  const std::vector<Point>& points = *this;
  for (unsigned i = 0; i < points.size() - 1; i++) {
    if (p.contains(points[i])) {
      return true;
    } else if ((p.x >= points[i].x && p.x <= points[i+1].x) || 
               (p.x <= points[i].x && p.x >= points[i+1].x)) {
      if ((p.y >= points[i].y && p.y <= points[i+1].y) || 
          (p.y <= points[i].y && p.y >= points[i+1].y)) {

        return true;
      }
    }
  }
  
  return false;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  limits.push_back(Point(x0, y0));
  limits.push_back(Point(x1, y1));
}