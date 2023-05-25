//*****************************************************************
// File:   esolape.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Mayo 2023
// Coms:   Programa para el ejercicio 2 de examen prácticas tardes
//*****************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <chrono>
#include <string>
#include <math.h>

using namespace std;
#include "../practica3/maxsolape.hpp"

// Pre: r,s ∊ R ∧ r <= s
// Post: randDouble(r,s)= α ∧ α ∊ [r, s]
double randDouble(const double r, const double s) {
    if (r < s){
        return  double(rand()) / RAND_MAX * (s - r) + r;
    } else {
        return r;
    }
}

// Pre: r,s ∊ R ∧ r < s
// Post: randInter(inter, r, s) -> inter[0] = p; inter[1] = q ^
// ^ r <= p <= q <= s
void randInter(double inter[2], const double r, const double s) {
    inter[0] = randDouble(r, s);
    inter[1] = randDouble(inter[0], s);
    
}

int main() {
    const unsigned MAX_INTERVALOS = 10000;
    
    srand(time(nullptr));
    double inters[MAX_INTERVALOS][2];
        // inters contendrá la secuencia de intervalos tal como generada aleatoriamente
        for (unsigned i = 0; i < 5000; i++) {
            double inter[2];
            randInter(inter, 0, 100);
            inters[i][0] = inter[0];
            inters[i][1] = inter[1];
        }
        for (unsigned i = 5000; i < MAX_INTERVALOS; i++) {
            double inter[2];
            randInter(inter, 50, 150);
            inters[i][0] = inter[0];
            inters[i][1] = inter[1];
        }
        // Comienzo a preparar el algoritmo de DyV
        // Creo el registro que va a almacenar los intervalos aleatorios
        tpInter indinters[MAX_INTERVALOS];
        // Llama a la función que crea un vector tipo tpInter partiendo de la matriz inters[N][2]
        crearvind(inters, indinters, MAX_INTERVALOS);

        tpSolape encontradoDyV; // Para almacenar el resultado del solape 

        mergesortIndInters(indinters, 0, MAX_INTERVALOS-1); // Primero ordena de menor a mayor los intervalos contenidos en indinters
        encontradoDyV = maxSolDyV(indinters, 0, MAX_INTERVALOS-1);
    

        cout << "Por Divide y Vencerás, máximo solape encontrado:" << endl;
        cout << "Índice intervalo 1: " << encontradoDyV.interA << " Índice intervalo 2: " << encontradoDyV.interB 
             << " Solape: " << encontradoDyV.solape << endl;

    }

