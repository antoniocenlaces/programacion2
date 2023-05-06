#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#include "ordenar.hpp"

using namespace std;
//Pre: a < b
//Post: randInt(a,b)= α ∧ α ∊ [a, b]
int randInt(const int a, const int b) {
    return a + rand() % (b - a +1);
}

//Pre: valores es un vector de enteros con al menos numeros elementos
//Post: Muestra por salida estandard los primeros y los últimos
//      veinte valores del vector valores
void muestraVector(int valores[], const int numeros){
        unsigned i= 0;
        unsigned j = 0;
        // Muestra los primeros 20 elementos de valores
        while (i < numeros && i < 20) {
            while(j < 10 && i < numeros) {
                cout << setw(8) << valores[i];
                j++;
                i++;
            }
            cout << endl;
            j = 0;
        }
        // Muestra los 20 últimos
        // Primero verifica si el vector tiene más de 20 posiciones
        if ((numeros - 20) > 0) {
            i = numeros - 20;
            j = 0;
            cout << setw(40) << ". . ." << endl;
            while (i < numeros) {
            while(j < 10 && i < numeros) {
                cout << setw(8) << valores[i];
                j++;
                i++;
            }
            cout << endl;
            j = 0;
        }
        }
}

//Pre: numeros >= 0 ∧ inicial < final
//Post: valores[α] ∊ [a, b] ∀ α < numeros
void generaVector(int valores[], const int numeros, const int inicial,
            const int final) {
            for (unsigned i = 0; i < numeros; i++) {
                valores[i] = randInt(inicial, final);
            }
        }

int main(int numArg, char* v[]) {
    if (numArg == 4){
        srand(time(nullptr));
        // cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
        int numeros = atoi(v[1]); // Primer argumento: número de elementos a presentar
        int inicial = atoi(v[2]); // Valor inferior del intervalo
        int final = atoi(v[3]);   // Valor superior del intervalo
        int valores[numeros];
        generaVector(valores, numeros, inicial, final);
        muestraVector(valores, numeros);
        cout << "Voy a oredenar los números anteriores" << endl;
        clock_t ticksInicial = clock();
        ordenar(valores, numeros);
        clock_t ticksFinal = clock();
        muestraVector(valores, numeros);

        cout << endl;
        cout << "El tiempo empleado en la ordenación ha sido de "
                << fixed << setprecision(5) << double(ticksFinal - ticksInicial)
                    / CLOCKS_PER_SEC << "s" << endl;
        
        return 0;
    } else
    {
        return 1;
    }
    
}