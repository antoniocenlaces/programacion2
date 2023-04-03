//*****************************************************************
// File:   maxsolape.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Marzo 2023
// Coms:   Implementación de las funciones necesarias para la
//         práctica 3 que resuelve el máximo solape de n intervalos
//         de números reales por fuerza bruta y con el algoritmo de
//         divide y vencerás
//*****************************************************************

#include <iostream>
// #include <cstring>
// #include <math.h>
using namespace std;
#include "maxsolape.hpp"

// Pre: inter1 e Inter2 son dos registros de tipo tpInter ^
//      ^ inter1.ini <= inter1.fin ^ inter2.ini <= inter2.fin
//
// Post: intercambia los valores de inter1 con inter2
void intercambiaInter(tpInter inter1, tpInter inter2) {
    tpInter aux;
    aux = inter1;
    inter1 = inter2;
    inter2 = inter1;
}
// Cuando los intervalos están ordenados las posibilidades de superposición son:
// Caso A:
// a        b
// |________|
//             |______|
//             c      d
// Caso B:
// a        b
// |________|
//        |______|
//        c      d
// Caso C:
// a        b
// |________|
//  |______|
//  c      d

// Pre: a y b son el inicio y fin de un intervalo, respectivamente ^
//      c y d son el inicio y fin de un intervalo, respectivamente ^
//      a <= c
//
// Post: devuelve el solape de los intervalos
double solapeOrdenados(const double a, const double b, const double c, const double d) {
    if (b <= c) { // Caso A: no hay solape entre los intervalos ordenados
        return 0.0;
    } else if (b <= d) { // Caso B: hay solape y d >= b
        return abs(b - c);
    } else { // Caso C: hay solape y d < b ^ a <= c
        return abs(d - c);
    }
}

// maxSolFBruta devuelve un registro tpSolape en el que el campo solape
// es el maximo solape entre parejas de los n primeros intervalos de inters,
// y los campos interA e interB son los indices de dichos intervalos.
// Para la matriz inters de ejemplo, el resultado es solape=4.5, interA=0,
// interB=3
// (los valores de interA e interB pueden estar intercambiados, es decir,
// el resultado para el ejemplo anterior tambi�n puede ser solape=4.5,
// interA=3, interB=0).
tpSolape maxSolFBruta(double inters[N][2], int n) {
    tpSolape resultado;
    resultado.interA = 0;
    resultado.interB = 0;
    resultado.solape = 0.0;
    // En caso de n <= 1 resultado ya contiene el solape (0) y los índices
    // Para implementar fuerza bruta con dos bucles anidados
    for (unsigned i = 0; i < n - 1; i++) {
        cout << "Elemento externo " << i << " a: " << inters[i][0] << " b: " << inters[i][1] << endl;
        for (unsigned j = i + 1; j < n; j++) {
            double solape = 0.0;
            // En esta iteración de i comparamos a = inters[i][0]; b = inters[i][1]
            cout << "Elemento interno " << j << " a: " << inters[j][0] << " b: " << inters[j][1];
            if (inters[i][0] <= inters[j][0]){ // Los intervalos a comparar están ordenados
                solape = solapeOrdenados(inters[i][0], inters[i][1], inters[j][0], inters[j][1]);
            } else {
                solape = solapeOrdenados(inters[j][0], inters[j][1], inters[i][0], inters[i][1]);
            }
            cout << " Solape: " << solape << endl;
            if (solape > resultado.solape) {
                resultado.solape = solape;
                    resultado.interA = i;
                    resultado.interB = j;
            }
        } // Fin bucle interno
    } // Fin bucle externo
    return resultado;
}

// Crea un vector de tpInter con los n primeros intervalos de inters.
// Por ejemplo para la matrix inters de la funcion anterior y n=5, los
// valores de indinters seran:
// [{ind: 0, ini: 1.5, fin: 8.0},
//  {ind: 1, ini: 0.0, fin: 4.5},
//  {ind: 2, ini: 2.0, fin: 4.0},
//  {ind: 3, ini: 1.0, fin: 6.0},
//  {ind: 4, ini: 3.5, fin: 7.0}]
void crearvind(double inters[N][2], tpInter indinters[N], int n) {
    for (unsigned i = 0; i < n; i++) {
        indinters[i].ind = i;
        indinters[i].ini = inters[i][0];
        indinters[i].fin = inters[i][1];
    }
}