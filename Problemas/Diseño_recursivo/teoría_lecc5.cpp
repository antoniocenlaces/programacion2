// Problema Torres de Hanoi lección 5

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

// Pre: 0 ≤ n ∧ origen ̸= destino ∧ origen ̸= aux ∧ destino ̸= aux
// Post: Presenta por stdout un listado con la
// secuencia de movimientos a realizar
// para resolver el problema de las torres
// de Hanoi, con n discos desde origen
// hasta destino, utilizando como auxiliar
// la torre aux
void torresHanoi(int n, const char origen[],
const char destino[],
const char aux[]){
if (n > 0) {
    torresHanoi(n-1,origen,aux,destino);
    cout << origen << "->" << destino << endl;
    torresHanoi(n-1,aux,destino,origen);
    }
}

// Pre: 0 ≤ n
// Post: Presenta por stdout un listado con la
// secuencia de movimientos a realizar
// para resolver el problema de las torres
// de Hanoi, con n discos desde "izquierda"
// hasta "derecha", utilizando como auxiliar
// la torre "central"
void torresHanoi(int n){
torresHanoi(n,"izquierda","derecha","central");
}

int main() {
    torresHanoi(3);
}