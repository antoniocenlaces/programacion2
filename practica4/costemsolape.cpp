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
// #include <cstring>

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

// Pre: nombreFichero es una cadena de caractereres con la ruta y el nombre de un fichero 
// Post: Devuelve un flujo de escritura en f asociado al fichero indicado
void abreFicheroEscritura(string nombreFichero, ofstream &f)
{
    f.open(nombreFichero);
    if(!f.is_open())
    {
        cerr << "\x1b[1;31m" <<"ERROR AL CREAR EL FICHERO: \""<<nombreFichero <<"\". "<<"\x1b[0m"<<endl;
    }
}

// Pre: f es un flujo de escritura asociado a un fichero 
// Post: cierra el flujo
void cierraFicheroEscritura(ofstream &f)
{
    f.close();
}

int main() {
    srand(time(nullptr));
    double inters2[N][2] = {
       {1.5, 8.0},
       {0.0, 4.5},
       {2.0, 4.0},
       {1.0, 6.0},
       {3.5, 7.0}
   };
       double inters3[N][2] = {
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
       {-12.0, 9.0},
       {-99.37, 50.32},
       {-10.1, 8.2}
   };

    cout << "Dime el número de intervalos a crear: ";
    int n;
    cin >> n;
    double inters[n][2]; // = { {0.0, 100.0} };
    
    for (unsigned i = 0; i < n; i++) {
        double inter[2];
        randInter(inter, minini, maxfin);
        inters[i][0] = inter[0];
        inters[i][1] = inter[1];
    }

    tpSolape encontradoFB; // encontrado es variable tipo tpSolape donde guardo el resultado
                         // del solape máximo encontrado con fuerza bruta
    encontradoFB = maxSolFBruta(inters, n);
    // Muestra por pantalla el resultado encontrado con fuerza bruta
    cout << " Por fuerza bruta:" << endl;
    cout << "Intervalo 1: " << encontradoFB.interA << " Intervalo 2: " << encontradoFB.interB << " Solape: "
        << encontradoFB.solape << endl;
    
    // PRUEBAS de ordenación de un vector de tpInter
    tpInter indinters[N];
    // Llama a la función que crea un vector tipo tpInter partiendo de la matriz inters[N][2]
    crearvind(inters, indinters, n);
    cout << "Vector de intervalos sin ordenar: " << endl;
    muestraIndInters(indinters,0, n-1);
    mergesortIndInters(indinters, 0, n-1);
    cout << "Vector de intervalos ordenado: " << endl;
    muestraIndInters(indinters,0, n-1);

    tpSolape encontradoDyV;

    encontradoDyV = maxSolDyV(indinters, 0, n-1);

    cout << " Por Divide y Vencerás:" << endl;
    cout << "Intervalo 1: " << encontradoDyV.interA << " Intervalo 2: " << encontradoDyV.interB << " Solape: "
        << encontradoDyV.solape << endl;


}