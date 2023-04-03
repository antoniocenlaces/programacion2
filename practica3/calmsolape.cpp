//*****************************************************************
// File:   calmsolape.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Marzo 2023
// Coms:   Programa de pruebas para la
//         práctica 3 que resuelve el máximo solape de n intervalos
//         de números reales por fuerza bruta y con el algoritmo de
//         divide y vencerás
//*****************************************************************

#include <iostream>
// #include <cstring>

using namespace std;
#include "maxsolape.hpp"

int main() {
    double inters2[N][2] = {
       {1.5, 8.0},
       {0.0, 4.5},
       {2.0, 4.0},
       {1.0, 6.0},
       {3.5, 7.0}
   };
       double inters[N][2] = {
       {4.0, 7.5},
       {3.0, 5.0},
       {0.5, 2.5},
       {1.5, 8.0},
       {0.0, 1.5},
       {2.0, 4.0},
       {1.0, 6.0},
       {3.5, 7.0},
       {1.5, 8.0},
       {0.0, 4.5},
       {2.0, 4.0},
       {1.0, 6.0},
       {3.5, 7.0},
       {0.0, 0.0},
       {-10.0, 8.0},
       {-12.0, 9.0}
   };
    tpSolape encontrado;
    encontrado = maxSolFBruta(inters,16);
    cout << "Intervalo 1: " << encontrado.interA << " Intervalo 2: " << encontrado.interB << " Solape: "
        << encontrado.solape << endl;
    // 
    
    tpInter indinters[N];
    crearvind(inters, indinters, 16);

}