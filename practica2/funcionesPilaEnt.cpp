#include <iostream>
#include <iomanip>

using namespace std;

// Tipo PilaEnt y operaciones básicas para el trabajo con pilas de datos
#include "pilaEnt.hpp"


// * Notación empleada en las especificaciones:
// p = []  La pila p está vacía, es decir, almacena 0 datos
// p = [d_1, d_2, ..., d_K] la pila p almacena K datos. El más antiguo
//     es el dato d_1, el segundo más antiguo el dato d_2, etc., etc.,
//     y el más reciente es el dato d_K

// * Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// * Post: p = [d_1, d_2, ..., d_K] AND numDatos(p) = K
int numDatos(PilaEnt &p) {
    if (estaVacia(p)) {
        return 0;
    } else if (estaLlena(p)) {
        return DIM;
    } else {
        int dato = cima(p);
        desapilar(p);
        int s = numDatos(p);
        apilar(p, dato);
        return s + 1;
    }
}

// Pre:  p = [d_1, d_2, ..., d_K]  AND K >= 0 AND anchura >= 1
// Post: p = [d_1, d_2, ..., d_K] y presenta por pantalla un listado de
//       los datos apilados en la pila comenzando por la cima, d_K, y acabando
//       por el del fondo de la pila, d_1. Cada dato lo escribe en una línea,
//       empleando anchura caracteres y alineado a la derecha. Cada dato es
//       precedido por el carácter '|' y es seguido por los caracteres ' ' y
//       '|', tal como se  ilustra a continuación. Tras el último dato se
//       presenta una linea de la forma "+--...--+", seguida por una línea
//       en blanco:
//
//        |     d_K |
//        |     ... |
//        |     d_2 |
//        |     d_1 |
//        +---------+
void mostrar(PilaEnt &p, const int anchura = 3) {
    if (estaVacia(p)) {
        cout << "+" << setfill('-') << setw(anchura + 2) << "+" 
            << setfill(' ') << endl;
    } else {
        int dato = cima(p);
        cout << "|" << setw(anchura) << dato << " |" << endl;
        desapilar(p);
        mostrar(p, anchura);
        apilar(p, dato);
    }
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND anchura >= 1
// Post: p = [d_1, d_2, ..., d_K] y presenta por pantalla un listado de los
//       datos apilados en la pila comenzando por el del fondo de la pila, d_1,
//       y acabando por el de la cima de la pila, d_K. Cada dato lo escribe
//       en una línea, empleando anchura caracteres y alineado a la derecha.
//       Cada dato es precedido por el carácter '|' y es seguido por los
//       caracteres ' ' y '|', tal como se  ilustra a continuación. Antes
//       del primer dato se presenta una linea de la forma "+--...--+":
//
//        +---------+
//        |     d_1 |
//        |     d_2 |
//        |     ... |
//        |     d_K |
void mostrarInvertida(PilaEnt &p, const int anchura = 3) {
    if (!estaVacia(p)) {
        int dato = cima(p);        
        desapilar(p);
            mostrarInvertida(p, anchura);
            cout << "|" << setw(anchura) << dato << " |" << endl;
            apilar(p, dato);
    } else {
        cout << "+" << setfill('-') << setw(anchura + 2) << "+" 
                << setfill(' ') << endl;
    }
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// Post: p = [d_2, ..., d_K]
void eliminarFondo(PilaEnt &p) {
    if(!estaVacia(p)){
        int dato = cima(p);
        desapilar(p);
        if(!estaVacia(p)) {
            eliminarFondo(p);
            apilar(p, dato);
        }
    }
}

// Pre:  p = [d_1, ..., d_{(K-i)}, d_{(K-i+1)}, d_{(K-i+2)}, ..., d_K] AND 0<= K AND
//      and  1<= i <= K
// Post: p = [d_1, ..., d_{(K-i)}, d_{(K-i+2)}, ..., d_K]
void eliminar(PilaEnt &p, const int i) {
    if (numDatos(p) == i) {
        desapilar(p);
    } else {
        int dato = cima(p);
        desapilar(p);
        eliminar(p, i);
        apilar(p, dato);
    }
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// Post: p = [nuevo, d_1, d_2, ..., d_K]
void insertarEnFondo(PilaEnt &pila, const int nuevo) {
    if (estaVacia(pila)){
        apilar(pila, nuevo);
    } else {
        int dato = cima(pila);
        desapilar(pila);
        insertarEnFondo(pila, nuevo);
        apilar(pila, dato);
    }
}

void filtraPar(PilaEnt &p) {
       if (estaVacia(p)){
        return;
    } else {
        int dato = cima(p);
        desapilar(p);
        filtraPar(p);
        dato = dato % 2 == 0 ? 0 : dato;
        apilar(p, dato);
    }
}