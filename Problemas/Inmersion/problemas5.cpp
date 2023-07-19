// Serie de problemas 5. Diseño recursivo con inmersión
 

#include <iostream>
// #include <iomanip>
// #include <ctime>
// #include <cstdlib>

using namespace std;

// Problema 1. Debilitamiento postcondición.
//Pre: 1 ≤ n ≤ #vo ∧ n ≤ #vd
//Post: vd[0] = vo[n − 1] ∧ ∀α ∈ [1, n − 1].vd[α] = vo[α − 1]
void rotar(const int vo[], int vd[], const int n) {

}

// Problema 2. Debilitamiento postcondición.
const int N = 10;
using Mat = int[N][N];

// Pre: 0 ≤ f < N^2
// Post: nVeces(M,d) = Num (α, β) ∈ [0, f]^2.M[α][β] = d
int nVeces(const Mat M, int d, int f) {
    if (f == 0) { // f es la posición de un elemento de M numerándolos por filas de 0 a N^2-1
                  // Caso base es cuando solo queda un elemento
        if(M[0][0] == d) { // hay coincidencia
            return 1;
        } else {
            return 0;
        }
    } else { // f > 0 → hay al menos dos elementos en M
        int i,j; // 0 ≤ i < N → contador de filas
                 // 0 ≤ j < N → contador de columnas
        i = f / N; // fila actual = f / (número de filas)
        j = f - (N * i); // columna actual = dif. entre f y el número de elementos que hay en todas las filas hasta i
        if (M[i][j] == d) {
            return 1 + nVeces(M, d, f - 1);
        } else {
            return nVeces(M, d, f - 1);
        }
    }
}

// Pre: true
// Post: nVeces(M, d) = Num (α, β) ∈ [0, N − 1]^2.M[α][β] = d
int nVeces(const Mat M, int d){
    return nVeces(M, d, N * N - 1);
}

// Problema 2. Refuerzo precondición.

// En este caso f puede llegar a N^2 ya que la pre me da la suma hasta f-1
// Pre: 0 ≤ f ≤ N^2 ∧ sV = Num (α) ∈ [0, f^2 − 1].M[cociente(f,N)][f-(N*cociente(f,N))] = d
// Post: nVeces(M, d) = Num (α, β) ∈ [0, N − 1]^2.M[α][β] = d
int nVeces2(const Mat M, int d, int f, int sV) {
    if (f == N * N) {
        return sV;
    } else { // f > 0 → hay al menos dos elementos en M
        int i,j; // 0 ≤ i < N → contador de filas
                 // 0 ≤ j < N → contador de columnas
        i = f / N; // fila actual = f / (número de filas)
        j = f - (N * i); // columna actual = dif. entre f y el número de elementos que hay en todas las filas hasta i
        if (M[i][j] == d) {
            return 1 + nVeces2(M, d, f +1, sV + 1);
        } else {
            return nVeces2(M, d, f+1, sV);
        }
        
    }
}
// Pre: true
// Post: nVeces2(M, d) = Num (α, β) ∈ [0, N − 1]^2.M[α][β] = d
int nVeces2(const Mat M, int d){
    return nVeces2(M, d, 0, 0);
}