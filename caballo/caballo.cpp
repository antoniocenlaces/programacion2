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
#include <iomanip>
#include<unistd.h>

using namespace std;
#include "caballo.hpp"

//Pre: true
//Post: dentro(i, j) ↔ 0 ≤ i < N ∧ 0 ≤ j < N
bool dentro(int i, int j) {
    return (0 <= i && i < N && 0 <= j && j < N) ? true : false;
}

//Pre: true
//Post: ∀α ∈ [0, N − 1].∀β ∈ [0, N − 1].t[α][β] = 0
void initTab(Tablero t){
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++) {
            t[i][j] = 0;
        }
    }
}

//Pre: true
//Post: Muestra el tablero por "cout"
void writeTab(const Tablero t){
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++) {
            cout << setw(3) << t[i][j];
        }
        cout << endl;
    }
}

//Pre: 0 ≤ i < N ∧ 0 ≤ j < N ∧ 1 ≤ m ≤ 8
//Post: (ii, jj) será la casilla alcanzada desde
// (i, j) con el movimiento m
void move(int i, int j, int& ii, int& jj, int m) {
    ii = i + MOVIMIENTOS[m - 1][0];
    jj = j + MOVIMIENTOS[m - 1][1];
    // if (ii < 0 || ii >= N || jj < 0 || jj >= N) {
    //     ii = i;
    //     jj = j;
    // }
}

//Pre: "t" tiene ya recorridos "numExitos"
// casillas desde la inicial."(i,j)"
// es una casilla alcanzable por el caballo
// desde la última del recorrido
//Post: Si completa un recorrido desde "(i,j)"
// toma valor "true", "numExitos"=N2
// y el recorrido se almacena en "t"
// Si no, devuelve falso; "t" y "numExitos"
// no se modifican
bool caballo(Tablero t, int i, int j, int &numExitos, int &llamada){
    llamada++;
    if (!dentro(i,j)) { // fuera de los límites
            return false;
        } else if (t[i][j] != 0) { // ocupada casilla
            return false;
        } else {
            numExitos++; 
            t[i][j] = numExitos; 
            writeTab(t);
            cout << endl; // Separa un tablero del anterior
            // usleep( 1000 ); //sleeps for 1000 μsecond
        } 
        if (numExitos == N*N) { // acabado con éxito
         return true;
        } else {
            int mov = 1;
            bool exito = false;
            while (mov<=8 && !exito) {
            int ii, jj;
            move(i, j, ii, jj, mov);
            exito = caballo(t, ii, jj, numExitos, llamada);
            mov++;
        }

        if(!exito) { //fracaso: retroceder
        numExitos--;
        t[i][j] = 0;
        }
        return exito;

        }
}