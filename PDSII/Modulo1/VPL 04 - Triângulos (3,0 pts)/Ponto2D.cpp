#include "Ponto2D.hpp"

Ponto2D::Ponto2D() {}

Ponto2D::Ponto2D(double x, double y) {
    _x = x;
    _y = y;
}

double Ponto2D::calcular_distancia(Ponto2D *ponto) {
    double dx = ponto->_x - _x;
    double dy = ponto->_y - _y;

    return sqrt(dx*dx + dy*dy);
}