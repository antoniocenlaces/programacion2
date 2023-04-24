//*****************************************************************
// File:   prueba_caballo.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Abril 2023
// Coms:   Programa de pruebas para el ejercicio de recorrer un
//         tablero de NxN casillas con los movimientos del caballo
//         del ajedrez, pasando una sola vez por cada casilla
//*****************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>
// #include <cstring>

using namespace std;
#include "caballo.hpp"

int main() {
    cout << "Probando a borrar todo;" << endl;
    cout << "Introduce un entero: ";
    int a;
    cin >> a;
    cout << "\033[2J\033[0m";
    cout << "\x1b[31;43m" << "Ahora con colores" << "\x1b[0m"<< endl;
    return 0;
}