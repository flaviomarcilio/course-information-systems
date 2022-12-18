#include <iostream>
#include <iomanip>

#include "Triangulo.hpp"
#include "Ponto2D.hpp"

using namespace std;

int main() {

    Ponto2D pontos[3];
    double x, y;

    // Triangulo 1
    // for (int i=0; i<3; i++) {
    //     cin >> x >> y;
    //     pontos[i] = Ponto2D(x, y);
    // }
    pontos[0] = Ponto2D(2.0, 2.0);
    pontos[1] = Ponto2D(2.0, 5.0);
    pontos[2] = Ponto2D(4.0, 2.0);

    Triangulo *triangulo1 = new Triangulo(pontos[0], pontos[1], pontos[2]);

    cout << "Triangulo 1" << endl;
    cout << "a: " << pontos[0].calcular_distancia(&pontos[1]) << endl;
    cout << "b: " << pontos[1].calcular_distancia(&pontos[2]) << endl;
    cout << "c: " << pontos[2].calcular_distancia(&pontos[0]) << endl;
    cout << "Perimetro: " << triangulo1->calcular_perimetro() << endl;
    cout << "Area: " << triangulo1->calcular_area() << endl;
    cout << endl;

    // Triangulo 2
    // for (int i=0; i<3; i++) {
    //     cin >> x >> y;
    //     pontos[i] = Ponto2D(x, y);
    // }
    pontos[0] = Ponto2D(4.0, 5.0);
    pontos[1] = Ponto2D(4.0, 8.0);
    pontos[2] = Ponto2D(6.0, 5.0);

    Triangulo *triangulo2 = new Triangulo(pontos[0], pontos[1], pontos[2]);

    cout << "Triangulo 2" << endl;
    cout << "a: " << pontos[0].calcular_distancia(&pontos[1]) << endl;
    cout << "b: " << pontos[1].calcular_distancia(&pontos[2]) << endl;
    cout << "c: " << pontos[2].calcular_distancia(&pontos[0]) << endl;
    cout << "Perimetro: " << triangulo2->calcular_perimetro() << endl;
    cout << "Area: " << triangulo2->calcular_area() << endl;
    cout << endl;

    cout << fixed << showpoint; 
    cout << setprecision(2);

    // Imprimindo as informacoes
    cout << triangulo1->calcular_area() << " " << triangulo2->calcular_area() << endl;
    cout << triangulo1->calcular_perimetro() << " " << triangulo2->calcular_perimetro() << endl;
    cout << triangulo1->comparar_area(triangulo2) << " " << triangulo2->comparar_area(triangulo1) << endl;

    delete triangulo1;
    delete triangulo2;

    return 0;
}