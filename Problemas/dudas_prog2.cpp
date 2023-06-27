#include <iostream>
using namespace std;

// Colección problemas 1 y 2

// Problema 12
// Devuelve el índice de un elemento de v tal que
// todos los elementos de índice menor son ≤ que ese elemento
// y
// todos los elementos de índice mayor son ≥ que ese elemento.
// Devuelve −1 si tal elemento no existe.
const int N = 25;
int selecciona(const double v[N]);
// Pre: N > 0
// Post: selecciona(v)=I ∧ 0 ≤ I ≤ N-1 ∧ I = ((¬(∀α ε[0, I-1].v[α]≤v[I] ∧ ∀α ε[I+1, N-1].v[α]≥v[I]) → -1) ∧ 
//       ((∀α ε[0, I-1].v[α]≤v[I] ∧ ∀α ε[I+1, N-1].v[α]≥v[I]) → I))

// Torres Hanoi en teoria_lecc5.cpp

// Problemas 4. Recursivas con inmersión

// Problema 1.

// Debilitamiento postcondición
// Pre: 1 ≤ n ≤ #v ∧ ∃α ∈ [0, n − 1].v[α]>0 ∧ 0 ≤ a ≤ N-1
// Post: posPriPos(v, n) = P ∧ a ≤ P ≤ N-1 ∧ v[P] > 0 ∧ ∀α ∈ [a, P − 1].v[α] ≤ 0
// Como defino a en la pre, ¿no es necesaria tb en la post?
int posPriPos(const double v[], const int n, const int a) {
    if (a == n-1) {
        return a;
    } else {
        return posPriPos(v, n, a+1);
    }
}
// Pre: 1 ≤ n ≤ #v ∧ ∃α ∈ [0, n − 1].v[α] > 0
// Post: posPriPos(v, n) = P ∧ 0 ≤ P ≤ n − 1
// ∧ v[P] > 0 ∧ ∀α ∈ [0, P − 1].v[α] ≤ 0
int posPriPos(const double v[], const int n){
    if (n == 1) {
        return n-1;
    } else {
        return posPriPos(v, n, 0);
    }
}

// Serie problemas4 de inmersión donde por ambos métodos se llega a la misma implementación