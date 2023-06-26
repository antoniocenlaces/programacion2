// Problema AR1.4 serie problemas resueltos recursiva

#include <iostream>
// #include <iomanip>
// #include <ctime>
// #include <cstdlib>

using namespace std;

// Pre: a >= 0 ∧ b > 0
// Post: cociente = a / b ∧ resto = a % b
void dividir(const int a, const int b, int& cociente , int& resto ) {
    if (a < b) {
        cociente = 0;
        resto = a;
    } else {
        dividir(a - b, b, cociente, resto);
        cociente = cociente +1;
    }
}

int main() {
    int cociente,resto;
    cout << "Valor de a: ";
    int a;
    cin >> a;
    cout << "Valor de b: ";
    int b;
    cin >> b;
    dividir(a, b, cociente, resto);
    cout << a << "/" << b << "= " << cociente << endl;
    cout << a << "%" << b << "= " << resto << endl << endl;

    cout << "Operadores de c++:" << endl;
    cout << a << "/" << b << "= " << a / b << endl;
    cout << a << "%" << b << "= " << a % b << endl;
}