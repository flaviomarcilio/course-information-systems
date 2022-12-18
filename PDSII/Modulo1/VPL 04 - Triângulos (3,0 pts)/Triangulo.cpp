#include "Triangulo.hpp"

Triangulo::Triangulo(Ponto2D p1, Ponto2D p2, Ponto2D p3) {

    this->_p1 = Ponto2D(p1._x, p1._y);
    this->_p2 = Ponto2D(p2._x, p2._y);
    this->_p3 = Ponto2D(p3._x, p3._y);
}

double Triangulo::calcular_area() {

    double p = this->calcular_perimetro() / 2.0;
    double a = _p1.calcular_distancia(&_p2);
    double b = _p2.calcular_distancia(&_p3);
    double c = _p3.calcular_distancia(&_p1);

    return sqrt(p*(p - a)*(p - b)*(p - c));
}

double Triangulo::calcular_perimetro() {
    return _p1.calcular_distancia(&_p2) + _p2.calcular_distancia(&_p3) + _p3.calcular_distancia(&_p1);
}

int Triangulo::comparar_area(Triangulo *triangulo) {

    double _area = this->calcular_area();
    double area = triangulo->calcular_area();

    if (_area > area) {
        return 1;
    } else if (_area == area ) {
        return 0;
    } else {
        return -1;
    }
}