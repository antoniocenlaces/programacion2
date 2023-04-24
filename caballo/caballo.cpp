//*********************************************************************
// File:   caballo.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Abril 2023
// Coms:   Implementación de las funciones necesarias para el ejercicio
//         del caballo que resuelve el problema de recorrer un
//         tablero de NxN casillas con los movimientos del caballo
//         del ajedrez, pasando una sola vez por cada casilla
//*********************************************************************

#include <iostream>

// #include <cstring>
#include <cmath>


using namespace std;
#include "caballo.hpp"

//Pre: true
//Post: dentro(i, j) ↔ 0 ≤ i < N ∧ 0 ≤ j < N
bool dentro(int i, int j) {
    return (0 <= i && i < N && 0 <= j && j < N) ? true : false;
}

//Pre: 0 ≤ i < N ∧ 0 ≤ j < N ∧ 1 ≤ m ≤ 8
//Post: (ii, jj) será la casilla alcanzada desde
// (i, j) con el movimiento m
void move(int i, int j, int& ii, int& jj, int m) {

}