//*****************************************************************
// File:   pruebas02.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2022
// Coms:   Programa de pruebas del trabajo con pilas
//         de datos enteros y del comportamiento de las funciones
//         definidas en el fichero "funcionesPilaEnt.hpp"
//         Para la práctica 2
//*****************************************************************

#include <iostream>
#include <cstring>

using namespace std;

// Funciones diseñadas de forma recursiva que trabajan
// con pilas que almacenan datos de enteros
#include "funcionesPilaEnt.hpp"


// Pre: ---
// Post: Ilustra el trabajo con pilas de datos enteros
void pruebasPilaEnteros() {
    // Define una pila de datos, P, que almacena datos de tipo 'int'
    PilaEnt P;
    // Vacía la pila P
    vaciar(P);
    // PRIMOS almacena los números primos menores que 100
    const int PRIMOS[] = {
        2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
    };
    // Apila en P los NUM primeros números primos
    const int NUM = 25;
    for (int i = 1; i <= NUM; ++i) {
        apilar(P, PRIMOS[i-1]);
    }
    // Muestra por pantalla el contenido de P
    cout << "Se han apilado los " << numDatos(P)
         << " primeros numeros primos:" << endl << endl;
    mostrar(P, 10);
    // Muestra por pantalla los datos de P en orden inverso
    cout << "Y esta es la pila invertida:" << endl << endl;
    mostrarInvertida(P);
    // Elimina un dato de la pila P y muestra su contenido
    cout << endl << "Se ha eliminado su sexto dato:" << endl << endl;
    eliminar(P, 6);
    mostrar(P);
    // Elimina otro dato de la pila P y muestra su contenido
    cout << "Se ha eliminado su tercer dato:" << endl << endl;
    eliminar(P, 3);
    mostrar(P);
    // Elimina el dato del fondo de la pila P y muestra su contenido
    cout << "Se ha eliminado el dato del fondo de la pila:"
         << endl << endl;
    eliminarFondo(P);
    mostrar(P);
    // Inserta los datos 123001 y 9229 en el fondo de la pila P y
    // muestra su contenido
    insertarEnFondo(P, 123002);
    insertarEnFondo(P, 9220);
    cout << "Se han insertado 123001 y 9229 en el fondo de la pila:"
         << endl << endl;
    mostrar(P, 6);

     const int PRIMOS2[] = {
        2,  3,  6,  7, 8, 13, 16, 19, 20, 14,
        31, 37, 41, 22, 47, 12, 59, 1004, 67, 71,
        5782, 79, 83, 684, 97
    };
    // Apila en P los NUM primeros números primos
    
    for (int i = 1; i <= NUM; ++i) {
        apilar(P, PRIMOS2[i-1]);
    }

    cout << "Nueva pila antes de filtrar:"
         << endl << endl;
    mostrar(P,8);

    filtraPar(P);
    cout << "Se han filtrado los pares de la pila:"
         << endl << endl;
    mostrar(P,8);
}


// Programa de prueba que ilustra el trabajo con pilas de datos de enteros
int main() {
    pruebasPilaEnteros();
    return 0;
}
