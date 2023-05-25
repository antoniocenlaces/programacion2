//*****************************************************************
// File:   costemsolape.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Mayo 2023
// Coms:   Programa de pruebas para la
//         práctica 4 para realizar el análisis experimental
//         del coste de algoritmos
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

// Pre: 0 <= p <= f < N
// Post: Muestra las componentes de p a f de un vector de tpInter con el formato:
// [{ind: 0, ini: 1.5, fin: 8.0},
//  {ind: 1, ini: 0.0, fin: 4.5},
//  {ind: 2, ini: 2.0, fin: 4.0},
//  {ind: 3, ini: 1.0, fin: 6.0},
//  {ind: 4, ini: 3.5, fin: 7.0}]
void muestraIndInters(tpInter indinters[N], const int p, const int f) {
    cout << fixed << setprecision(2) << "[";
    if (f-p+1 > 0){ 
        // Si el intervalo [p, f] contiene al menos un elemento, muestro linea 1
        cout << "{ind: " << setw(6) << indinters[p].ind << ", ini: " << setw(6)
            << indinters[p].ini << ", fin: " << setw(6) << indinters[p].fin << "}," << endl;
        // Muestra en bucle el resto de líneas excepto la f (última a mostrar)
        for (unsigned i = p+1; i < f; i++){ 
            cout << " {ind: " << setw(6) << indinters[i].ind << ", ini: " << setw(6) 
                << indinters[i].ini << ", fin: " << setw(6) << indinters[i].fin << "}," << endl;
        }
        if (f > p) {
        // Si aún queda una última línea por mostrar
        cout << " {ind: " << setw(6) << indinters[f].ind << ", ini: " << setw(6) 
                << indinters[f].ini << ", fin: " << setw(6) << indinters[f].fin << "}";
        }
    }
    cout << "]" << setprecision(4) << endl;
}

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
    

        cout << " Por Divide y Vencerás:" << endl;
        cout << "Intervalo 1: " << encontradoDyV.interA << " Intervalo 2: " << encontradoDyV.interB 
             << " Solape: " << encontradoDyV.solape << endl;

    }

   

    // Muestra por pantalla el resultado encontrado con fuerza bruta
    // cout << " Por fuerza bruta:" << endl;
    // cout << "Intervalo 1: " << encontradoFB.interA << " Intervalo 2: " << encontradoFB.interB << " Solape: "
    //     << encontradoFB.solape << endl;
    
  
    // cout << "Vector de intervalos sin ordenar: " << endl;
    // muestraIndInters(indinters,0, n-1);
    // mergesortIndInters(indinters, 0, n-1);
    // cout << "Vector de intervalos ordenado: " << endl;
    // muestraIndInters(indinters,0, n-1);

    // tpSolape encontradoDyV;

    // encontradoDyV = maxSolDyV(indinters, 0, n-1);

    // cout << " Por Divide y Vencerás:" << endl;
    // cout << "Intervalo 1: " << encontradoDyV.interA << " Intervalo 2: " << encontradoDyV.interB << " Solape: "
    //     << encontradoDyV.solape << endl;


