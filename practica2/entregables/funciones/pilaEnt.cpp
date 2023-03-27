//*****************************************************************
// File:   pilaEnt.cpp
// Author: Antonio J. González Almela. Programación II. Universidad de Zaragoza
// Date:   febrero 2022
// Coms:   Implementación de las funciones de manejo de pila
//         definidas en pilaEnt.hpp
//*****************************************************************

#include <iostream>
#include <cstring>

using namespace std;
#include "pilaEnt.hpp"

//  Notación empleada en la especificación de funciones:
//    p = [] la pila está vacía, es decir, almacena 0 datos
//    p = [d_1, d_2, ..., d_K] la pila almacena K datos. El más antiguo
//        es el dato d_1, el segundo más antiguo el dato d_2, etc., etc.,
//        y el más reciente es el dato d_K

// Pre:  ---
// Post: p = []
void vaciar(PilaEnt &p) {
    p.ocupadas=0;
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
// Post: p = [d_1, d_2, ..., d_K, nuevo]
void apilar(PilaEnt &p, const int nuevo) {
    if(p.ocupadas < DIM){
        p.pila[p.ocupadas] = nuevo;
        p.ocupadas++;
    }
}

// Pre:  p = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
// Post: p = [d_1, d_2, ..., d_(K-1)]
void desapilar(PilaEnt &p) {
    if(p.ocupadas > 0) {
        p.ocupadas--;
    }
}

// Pre:  p = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
// Post: cima(p) = d_K
int cima(const PilaEnt &p) {
    if (p.ocupadas > 0) {
        return p.pila[p.ocupadas-1];
    } else {
        return 0;
    }
}

// Pre: ---
// Post: estaVacia(p) = (p = [])
bool estaVacia(const PilaEnt &p) {
    return p.ocupadas == 0;
}

// * Pre: p = [d_1, d_2, ..., d_K]
// * Post: estaLlena(p) = (K = DIM])
bool estaLlena(const PilaEnt &p) {
    return p.ocupadas == DIM;
}