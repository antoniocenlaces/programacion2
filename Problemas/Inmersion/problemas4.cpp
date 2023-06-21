// Serie de problemas 4. Diseño recursivo con inmersión
 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
// Pre: 1 ≤ n ≤ #v
// Post: muestra un vector de n componentes por cout
void muestraV(double v[], const int n) {
    cout << fixed << setprecision(2) <<"{";
    for (int i = 0; i < n - 1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[n - 1] << "}" << endl;
}

// Problema 1. Debilitamiento Postcondición
// Pre: 1 ≤ n ≤ #v ∧ ∃α ∈ [0, n − 1].v[α] > 0 ∧ 0 ≤ a ≤ n-1
// Post: posPriPos(v, n) = P ∧ 0 ≤ P ≤ n − 1
// ∧ v[P ] > 0 ∧ ∀α ∈ [0, P − 1].v[α] ≤ 0 ∧ ∀α ∈ [0, a − 1].v[α] ≤ 0
int posPriPos(const double v[], const int n, const int a) {
    if (a == n - 1) {
        return a; // a = n-1 -> v[a] > 0 ∧ ∀α ∈ [0, n − 2].v[α] ≤ 0
    } else {
        return posPriPos(v, n, a + 1);
    }
}

// Pre: 1 ≤ n ≤ #v ∧ ∃α ∈ [0, n − 1].v[α] > 0
// Post: posPriPos(v, n) = P ∧ 0 ≤ P ≤ n − 1
// ∧ v[P ] > 0 ∧ ∀α ∈ [0, P − 1].v[α] ≤ 0
int posPriPos(const double v[], const int n) {
    if (n == 1) {
        return n-1;
    } else {
        return posPriPos(v, n, 0);
    }
}

int main() {
    int n = 10;
    double v[n] = {-2, 0, -7, -3, -1, -2, -9, 0, -1, 1};
    int pos = posPriPos(v, n);
    muestraV(v, n);
    cout << "La posición del primer positivo es: " << pos << endl;
}