// Serie de problemas 6. Esquemas algorítmicos
 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
// Problema 1
//Pre: 0 ≤ n
//Post: pot(n) = 2^n
double pot1(const int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 2;
    } else {
        int p = pot1(n / 2);
        if (n % 2 == 0) {
            return p * p;
        } else {
            return 2 * p * p;
        }
    }
}

//Pre: 0 ≤ n
//Post: pot10(n) = 10^n
int pot10(const int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 10;
    } else {
        int p = pot10(n / 2);
        if (n % 2 == 0) {
            return p * p;
        } else {
            return 10 * p * p;
        }
    }
}

// Problema 1 con base real y exponente entero

// Pre: 0 ≤ n
// Post potencia(const double b, const int exp) = b^n
double potencia(const double b, const int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return b;
    } else {
        double p = potencia(b, exp / 2);
        if (exp % 2 == 0) {
            return p * p;
        } else {
            return b * p * p;
        }
    }
}

int main() {
    cout << "Introduce un número: ";
    int n;
    cin >> n;
    double pot = pot1(n);
    cout << "Pot(" << n << ")=" <<  pot << endl;
    
    cout << "Introduce un número: ";
    cin >> n;
    int potd = pot10(n);
    cout << "Pot10(" << n << ")=" <<  potd << endl;

    cout << "Con algoritmo en base b:" << endl;
    cout << "2.15^3=" << potencia(2.15,3) << endl;
}