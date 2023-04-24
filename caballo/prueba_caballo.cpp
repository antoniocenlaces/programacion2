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
    // cout << "Probando a borrar todo;" << endl;
    // cout << "Introduce un entero: ";
    // int a;
    // cin >> a;
    // cout << "\033[2J\033[0m";
    // cout << "\x1b[1;31;43m" << "Ahora con colores" << "\x1b[0m"<< endl;
    // cout << "Escritura normal" << endl;

    Tablero tab;
    bool exito;
    int numExitos = 0;
    initTab(tab);
    int llamada = 0;
    exito = caballo(tab, 2, 3, numExitos, llamada);
    if (exito) {
        // cout << "\033[2J\033[0m";
    writeTab(tab);
    } else {
    cout << "Imposible" << endl;
    }
    cout << "Llamadas realizadas: " << llamada << endl;
    return 0;
}