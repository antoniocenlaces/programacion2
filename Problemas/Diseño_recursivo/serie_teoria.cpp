// Problema 1 serie problemas teoría lección 4

#include <iostream>
#include <iomanip>
// #include <ctime>
// #include <cstdlib>

using namespace std;

//Pre: a < b
//Post: randInt(a,b)= α ∧ α ∊ [a, b]
int randInt(const int a, const int b) {
    return a + rand() % (b - a + 1);
}

//Pre: r,s ∊ R ∧ r < s
//Post: randDouble(r,s)= α ∧ α ∊ [r, s]
double randDouble(const double r, const double s) {
    return  double(rand()) / RAND_MAX * (s - r) + r;
}

//Pre: n >= 0
//Post: muestra por pantalla las n primeras componentes de un vector de enteros
void muestraInt(const int v[], const int n) {
    cout << "[ ";
    for (int i = 0; i < n - 1; i++) {
        cout << v[i] << ", ";
    }
    if (n == 0) {
        cout << "]";
    } else {
        cout << v[n - 1] << " ]";
    }
    cout << endl;
}

//Pre: n >= 0
//Post: muestra por pantalla las n primeras componentes de un vector de reales
void muestraDouble(const double v[], const int n) {
    cout << fixed << setprecision(3) << "[ ";
    for (int i = 0; i < n - 1; i++) {
        cout << v[i] << ", ";
    }
    if (n == 0) {
        cout << "]";
    } else {
        cout << v[n - 1] << " ]";
    }
    cout << endl;
}

//Pre: n>=0 ^ minInt, maxInt ∊ Z ^ minInt < maxInt
//Post: creaVectorInt(v,n, minInt, maxInt) devuelve vector v con n enteros entre minInt y maxInt
void creaVectorInt(int v[], const int n, const int minInt, const int maxInt) {
    for (int i = 0; i < n; i++) {
        v[i] = randInt(minInt, maxInt);
    }
}

//Pre: n>=0 ^ minInt, maxInt ∊ R ^ minInt < maxInt
//Post: creaVectorInt(v,n, minInt, maxInt) devuelve vector v con n enteros entre minInt y maxInt
void creaVectorDouble(double v[], const int n, const double minD, const double maxD) {
    for (int i = 0; i < n; i++) {
        v[i] = randDouble(minD, maxD);
    }
}

//Problema 1
    //Pre: 0 ≤ n ≤ #v
    //Post: esPos(v, n) = ∀α ∈ [0, n − 1].v[α] > 0
    bool esPos(const double v[], int n) {
        if (n > 0) {
            if (v[n - 1] <= 0) {
                return false;
            } else {
                return esPos(v, n - 1);
            }
        } else {
            return true;
        }
    }
//Problema 1 v2
    //Pre: 0 ≤ n ≤ #v
    //Post: esPos(v, n) = ∀α ∈ [0, n − 1].v[α] > 0
    bool esPos1(const double v[], int n) {
        if (n == 0) {
            return true;
            } else if (v[n - 1] <= 0) {
                return false;
            } else {
                return esPos(v, n - 1);
        }
    }

// Problema 2
    //Pre: 1 ≤ n ≤ #v
    //Post: ordenado(v, n) = ∀α ∈ [0, n − 2].v[α] ≤ v[α + 1]
    bool ordenado(const double v[], int n) {
        if (n == 0) { // caso base
            return true;
        } else if (v[n - 2] > v[n - 1]) {
            return false;
        } else {
            return ordenado(v, n - 1);
        }
    }

int main() {
    srand(time(nullptr));
    cout << "¿Cuántos elementos quieres en el vector? (>=0): ";
    int n;
    do{ 
        cin >> n;
    } while (n < 0);

    //Crea vector de enteros
    int v[n];
    int minInt = 1,maxInt = 0;
    do {
        cout << "Entero menor del vector: ";
        cin >> minInt;
        cout << "Entero mayor del vector: ";
        cin >> maxInt;
    } while (maxInt <= minInt);

    creaVectorInt(v, n, minInt, maxInt);

    muestraInt(v, n);

    double v1[]={1,2,3,4,5,6,7,8,9,10};
    cout << "El vector:" << endl;
    muestraDouble(v1,10);
    if (ordenado(v1, 10)) {
        cout << "Está ordenado";
    } else {
        cout << "NO Está ordenado";
    }
    cout << endl;
    cout << endl;
    v1[2]=9.0;
    cout << "El vector:" << endl;
    muestraDouble(v1,10);
    if (ordenado(v1, 10)) {
        cout << "Está ordenado";
    } else {
        cout << "NO Está ordenado";
    }
    cout << endl;

     //Crea vector de reales
    double vr[n];
    double minD = 1.0,maxD = 0.0;
    do {
        cout << "Real menor del vector: ";
        cin >> minD;
        cout << "Real mayor del vector: ";
        cin >> maxD;
    } while (maxD <= minD);

    creaVectorDouble(vr, n, minD, maxD);
    
    cout << "El vector:" << endl;
    muestraDouble(vr, n);
    if (esPos(vr, n)) {
        cout << "Tiene todos sus elementos positivos";
    } else {
        cout << "NO Tiene todos sus elementos positivos";
    }
    cout << endl;
    cout << endl;

    cout << "El vector:" << endl;
    muestraDouble(vr, n);
    if (esPos1(vr, n)) {
        cout << "Tiene todos sus elementos positivos";
    } else {
        cout << "NO Tiene todos sus elementos positivos";
    }
    cout << endl;
}