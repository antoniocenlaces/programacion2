// Serie de problemas 4. Diseño recursivo con inmersión
 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
// Pre: 0 ≤ n ≤ #v
// Post: muestra un vector de n componentes por cout
void muestraV(double v[], const int n) {
    cout << fixed << setprecision(2) <<"{";
    for (int i = 0; i < n - 1; i++) {
        cout << v[i] << ", ";
    }
    if (n > 0) {
        cout << v[n - 1];
    }
    cout << "}" << endl;
}

// Problema 1. Debilitamiento Postcondición
// Pre: 1 ≤ n ≤ #v ∧ ∃α ∈ [0, n − 1].v[α] > 0 ∧ 0 ≤ a ≤ n-1
// Post: posPriPos(v, n) = P ∧ 0 ≤ P ≤ n − 1
// ∧ v[P ] > 0 ∧ ∀α ∈ [0, P − 1].v[α] ≤ 0 ∧ ∀α ∈ [0, a − 1].v[α] ≤ 0
int posPriPos(const double v[], const int n, const int a) {
    if (a == n - 1) {
        return a; // a = n-1 -> v[a] > 0 ∧ ∀α ∈ [0, n − 2].v[α] ≤ 0
    } else if (v[a] > 0) {
        return a;
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

// Problema 2. Invertir
// Refuerzo precondición

// Pre: 0 ≤ n ≤ #v ∧ 0 ≤ inv ≤ n/2 ∧ ∀α ∈ [0, n − 1].
//      (x[α]=v[n-1-α] ∧ v[α]=x[n-1-α])
// Post: ∀α ∈ [0, n − 1].x[α] = v[n − 1 − α]
void invertir(const double v[], int n, double x[], int inv) {
    if (inv <= n / 2) {
        x[inv] = v[n - 1 - inv];
        x[n - 1 - inv] = v[inv];
        invertir(v, n, x, inv + 1);
    }
}
// Pre: 0 ≤ n ≤ #v
// Post: ∀α ∈ [0, n − 1].x[α] = v[n − 1 − α]
void invertir(const double v[], int n, double x[]) {
    invertir(v, n, x, 0);
}

int main() {
    int n = 12;
    double v[n] = {-2, 0, -7, 2, -1, 1.8, -9, 0, -1, 1, 0, -1};
    int pos = posPriPos(v, n);
    muestraV(v, n);
    cout << "Problema 1" << endl;
    cout << "La posición del primer positivo es: " << pos << endl;
    cout << "Problema 2" << endl;
    cout << "Vector antes de invertir: " << endl;
    muestraV(v, n);
    double x[n] = {0};
    invertir(v, n, x);
    cout << "Vector invertido: " << endl;
    muestraV(x, n);
    cout << "Ahora con n=0" << endl;
    n=0;
     muestraV(v, n);
     invertir(v, n, x);
     muestraV(x, n);

     cout << "Ahora con n=1" << endl;
    n=1;
     muestraV(v, n);
     invertir(v, n, x);
     muestraV(x, n);

     cout << "Ahora con n=2" << endl;
    n=2;
     muestraV(v, n);
     invertir(v, n, x);
     muestraV(x, n);
}