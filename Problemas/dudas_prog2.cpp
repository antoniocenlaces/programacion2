// Colección problemas 1 y 2

#include <iostream>
using namespace std;

// Problema 12
// Devuelve el índice de un elemento de v tal que
// todos los elementos de índice menor son ≤ que ese elemento
// y
// todos los elementos de índice mayor son ≥ que ese elemento.
// Devuelve −1 si tal elemento no existe.
const int N = 25;
int selecciona(const double v[N]);
// Pre: N > 0
// Post: selecciona(v)=I ∧ I = ((¬(∀α ε[0, I-1].v[α]≤v[I] ∧ ∀α ε[I+1, N-1].v[α]≥v[I]) → -1) ∧ 
//       ((∀α ε[0, I-1].v[α]≤v[I] ∧ ∀α ε[I+1, N-1].v[α]≥v[I]) → I))