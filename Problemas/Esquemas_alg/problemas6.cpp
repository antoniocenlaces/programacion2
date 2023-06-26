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
}