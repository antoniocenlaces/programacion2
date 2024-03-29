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
// ∧ v[P] > 0 ∧ ∀α ∈ [0, P − 1].v[α] ≤ 0 ∧ ∀α ∈ [0, a − 1].v[α] ≤ 0
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

// Intento 2 Problema 1. Debilitamiento Postcondición
// Pre: 1 ≤ n ≤ #v ∧ ∃α ∈ [0, n − 1].v[α] > 0 ∧ 0 ≤ a ≤ n-1
// Post: (posPriPos(v, n, a) = P ∧ 0 ≤ P ≤ n − 1
// ∧ v[P] > 0 ∧ ∀α ∈ [0, P − 1].v[α] ≤ 0) ∨ (posPriPos(v, n, a) = -1 ∧ ∀α ∈ [0, a].v[α] ≤ 0)
int posPriPos2(const double v[], const int n, const int a, int & iteracion) {
    iteracion++;
    cout << "Inicia llamada recursiva a posPriPos2 nº: " << iteracion << endl;
    if (a == 0) {
        if (v[a]>0){
            cout << "a=0 y v[0]>0 retorna 0" << endl;
            return a;
        } else {
            cout << "a=0 y v[0]≤0 retorna -1" << endl;
            return -1;
        }
    }
    if (v[a] > 0) { // a > 0 ∧ v[a] > 0
                    // Voy a ver los que están a su izqda.
        int pos = posPriPos2(v, n, a - 1, iteracion);
        cout << "Estoy en la pos a= " << a << " y v[a]>0 y a su izqda posPriPos2 responde: " << pos << endl;
        if (pos == -1) { // Todo lo que está a la izda de a es negativo → a es el resultado
        cout << "Como todos los elementos a la izda de a son neg devuelvo a" << endl;
            return a;
        } else { // Hay al menos un positivo a la izda de a
            if( pos == 0) { // Primer elemento de v es positivo
                return pos;
            } else { // pos > 0 ∧ v[pos] > 0
            cout << "Como pos > 0 ∧ v[pos] > 0 continuo la recursividad desde pos -1" << endl;
                return posPriPos2(v, n, pos - 1, iteracion);
            }
        }
    } else { // a > 0 ∧ v[a] ≤ 0
        cout << "a > 0 ∧ v[a] ≤ 0 continua recursividad en (a-1)" << endl;
        return posPriPos2(v, n, a - 1, iteracion);
    }
}
// Pre: 1 ≤ n ≤ #v ∧ ∃α ∈ [0, n − 1].v[α] > 0
// Post: posPriPos(v, n) = P ∧ 0 ≤ P ≤ n − 1
// ∧ v[P ] > 0 ∧ ∀α ∈ [0, P − 1].v[α] ≤ 0
int posPriPos2(const double v[], const int n) {
    if (n == 1) {
        return n-1;
    } else {
        int iteracion = 0;
        return posPriPos2(v, n, n-1, iteracion);
    }
}

// Problema 2. Invertir
// Refuerzo precondición

// Pre: 0 ≤ n ≤ #v ∧ 0 ≤ inv ≤ n/2 ∧ ∀α ∈ [0, inv − 1].
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
// En invertir con debilitamiento obtengo el mismo diseño:
// Pre: 0 ≤ n ≤ #v ∧ 0 ≤ p ≤ n/2
// Post: ∀α ∈ [p, n−1-p].(x[α]=v[n-1-α] ∧ v[α]=x[n-1-α])
// ¿ Para posPriPos e invertir hay una forma de ir de derecha a izqda?

// Problema 3. acumular
// Refuerzo precondición
// Pre: 1 ≤ n ≤ #v ∧ 1 ≤ a ≤ n ∧ ∀α ∈[0,a−1].z[α] = SUM[β=0,α](v[β]) 
//      ∧ z[0]=v[0]
// Post: ∀α ∈ [0, n − 1].z[α] = SUM[β=0,α](v[β])
void acumular(const int v[], int n, int z[], int a) {
    if (a < n){
        z[a] = z[a-1] + v[a];
        acumular(v, n, z, a + 1);
    }
}

// Pre: 1 ≤ n ≤ #v
// Post: ∀α ∈ [0, n − 1].z[α] = SUM[β=0,α](v[β])
void acumular(const int v[], int n, int z[]) {
    z[0]=v[0]; // Para garantizar la pre de la inmersión
    if (n > 1) {
        acumular(v, n, z, 1);
    }
}

// Problema 3. acumular
// Debilitamiento postcondición
// Pre: 1 ≤ n ≤ #v ∧ 0 ≤ f < n 
// Post: ∀α ∈ [0, f].z[α] = SUM[β=0,α](v[β])
void acumular2(const int v[], int n, int z[], int f) {
    if (f == 0) {
        z[0]=v[0];
    } else {
        acumular2(v, n, z, f - 1);
        z[f] = z[f-1] + v[f];
    }
}
// Pre: 1 ≤ n ≤ #v
// Post: ∀α ∈ [0, n − 1].z[α] = SUM[β=0,α](v[β])
void acumular2(const int v[], int n, int z[]) {
        acumular2(v, n, z, n - 1);
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

     n = 12;
    //  double v2[n] = {-1, 0, -7, 2, -1, -3, -9, 0, -1, 1, 0, -5};
    //  cout << "PosPriPos2 de:"<< endl;
    //  muestraV(v2, n);
    //  pos = posPriPos2(v2, n);
    //   cout << "La posición del primer positivo es: " << pos << endl;

      cout << "prueba de un bucle con preasignación" << endl;
      for (int i = 0; i != n - 1; ++i) {
        cout << "Valor contador: " << i << endl;
      }

}