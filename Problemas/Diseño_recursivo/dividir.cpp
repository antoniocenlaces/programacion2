// Problema AR1.4 serie problemas resueltos recursiva

#include <iostream>
#include <cmath>
// #include <iomanip>
// #include <ctime>
// #include <cstdlib>

using namespace std;

// Problema AR1.4
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

// Problema AR1.5
//Pre: b >= 0
//Post: multiplicar(a,b)=a*b
int multiplicar(const int a, const int b) {
    if (b == 0) {
        return 0;
    } else {
        if (b % 2 == 1){
            return a + multiplicar(2 * a, b /2);
        } else {
            return multiplicar(2 * a, b / 2);
        }
    }
}

// Problema AR1.6
// Pre: n >= 0 AND d >= ’0’ AND d <= ’9’
//  Post: Devuelve el número resultante de eliminar de <n> todos los
//        dígitos iguales a <d>.
int eliminar (const int n, const int d) {
    if ( n <= 9) {
        if (n == d) {
            return 0;
        } else {
            return n;
        }
    }
    if (n % 10 == d) {
        return eliminar(n / 10, d);
    } else {
        return n % 10 + eliminar(n / 10, d) * 10;
    }
}

// AR1.7

// Pre: n >= 0
// Post: Devuelve un entero cuyos dígitos son la siguiente permutación
//     de los dígitos de <n>:
//     - Los dígitos signiﬁcativos de <n>, a partir de las decenas,
//         se ubican en el valor devuelto una posición a la derecha.
//     -El dígito de las unidades de <n> sustituye, en el valor devuelto,
//         al dígito más signiﬁcativo de <n>.

int numDigitos(const int n) {
    if (n <= 9) {
        return 1;
    }
    return 1 + numDigitos(n / 10);
}

int rotarDerecha(const int n) {
    if (n <= 9) {
        return n;
    }
    return pow(10,numDigitos(n) - 1) * (n % 10) + n / 10;
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
    cout << a << "%" << b << "= " << a % b << endl << endl;

    cout << "Multiplicación recursiva:" << endl;
    cout << a << "*" << b << "= " << multiplicar(a, b) << endl << endl;
    cout << "Por compliador: " << a * b << endl;

    cout << endl << "Prueba de eliminar" << endl;
    int elimina;
    cout << "Dígito a eliminar de " << a << endl;
    cin >> elimina;
    cout << "Eliminando " << elimina << " queda: " << eliminar(a,elimina) << endl;

    cout << endl << "Rotar Derecha a: " << rotarDerecha(a) << endl;
}