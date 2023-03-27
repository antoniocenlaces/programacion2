//*****************************************************************
// File:   pruebas01.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2022
// Coms:   Programa de pruebas del comportamiento de las funciones
//         definidas en el módulo calculos
//         Para la práctica 1
//*****************************************************************

#include <iostream>
#include <cmath>
#include "calculos.hpp"

using namespace std;


// Pre:  <cifras> es el número de cifras de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar numCifras(n, b) es igual
//       a <cifras> o no lo es
void probarNumCifras(const int n, const int b, const int cifras) {
    int r = numCifras(n, b);
    if (r == cifras) {
        cout << "Ok. numCifras(" << n << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. numCifras(" << n << "," << b << ") = " << r << "  pero debiera ser "
             << cifras << endl;
    }
}


// Prueba el comportamiento de numCifras(n,10) para los siguientes valores de n:
// 0, 1, 9, 10, 99, 100, 999, 1000, ... , 99999, 100000, 99999 y 1000000
// y prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
// 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
void probarNumCifras() {
    // Prueba el comportamiento de numCifras(n) para los siguientes valores de n:
    // 0, 1, 9, 10, 99, 100, 999, 1000, ..., 99999, 100000, 99999 y 1000000
    probarNumCifras(0, 10, 1);
    probarNumCifras(1, 10, 1);
    int n = 10;
    int cifras = 2;
    while (n <= 1000000) {
        probarNumCifras(n - 1, 10, cifras-1);
        probarNumCifras(n, 10, cifras);
        n = 10 * n;
        cifras = cifras + 1;
    }
    cout << endl;
    // Prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
    // 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
    probarNumCifras(0, 2, 1);
    probarNumCifras(1, 2, 1);
    n = 2;
    cifras = 2;
    while (n <= 10000) {
        probarNumCifras(n - 1, 2, cifras-1);
        probarNumCifras(n, 2, cifras);
        n = 2 * n;
        cifras = cifras + 1;
    }
    cout << endl;
}


// Pre:  <n> es el número natural y <b> está comprendido entre 2 y 10
// Post: Informa si los valores devueltos al ejecutar cifra(n, i, b) corresponden
//       o no a la i-ésima cifra de <n>, cuando este número se escribe en base <b>
void probarCifra(const int n, const int b) {
    // Almaceno el número de cifras que tiene n
    int numDigitos = numCifras(n, b);
    // reconstruido será el número calculado llamando a la función cifra(n, i, b)
    int reconstruido = 0;
    for (unsigned i = numDigitos; i >= 1; i--) {
        reconstruido = reconstruido * b + cifra(n, i, b);
    }
     if (reconstruido == n) {
        cout << "Ok. probarCifra(" << n << "," << b << ") reconstruido= " << reconstruido << endl;
    } else {
        cout << "Mal. probarCifra(" << n << "," << b << ") reconstruido= " << reconstruido
             << "  pero debiera ser " << n << endl;
    }
}


// Prueba el comportamiento de cifra(n,i,b) para diferentes números naturales
// en las bases de numeración 2 y 10
void probarCifra() {
    // Pruebas de cifra(n,i,b) en base 10
    int b = 10;
    
    int i = 1;
    while(i >= 0 && i <= 2147483647) {
        probarCifra(i - 1, b);
        probarCifra(i, b);
        probarCifra(i + 1, b);
        i = i * 3;
    }
    b = 2;
    i = 1;
    while(i >= 0 && i <= 2147483647) {
        probarCifra(i - 1, b);
        probarCifra(i, b);
        probarCifra(i + 1, b);
        i = i * 3;
    }
    
    // probarCifra(1001, 10);
    // probarCifra(1234321, 10);
    // probarCifra(1024, 2);
    // probarCifra(109901, 10);
    // probarCifra(9000091, 2);
}


// Pre:  <n> es el número natural y <b> está comprendido entre 2 y 10 y <laMayor> es
//       el valor de la mayor de las cifras de <n> cuando se escribe en base <b>
// Post: Informa si el valor devuelto al ejecutar cifraMayor(n, b) coincide con el
//       de <laMyor>, cuando <n> se escribe en base <b>
void probarCifraMayor(const int n, const int b, const int laMayor) {
    int m = cifraMayor(n, b);
    if (m == laMayor) {
        cout << "Ok. cifraMayor(" << n << "," << b << ") = " << m << endl;
    } else {
        cout << "Mal. cifraMayor(" << n << "," << b << ") = " << m << "  pero debiera ser "
             << laMayor << endl;
    }
}


// Prueba el comportamiento de cifraMayor(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMayor() {
    // Pruebas en base 10
    int b = 10;
    probarCifraMayor(0, b, 0);
    probarCifraMayor(1, b, 1);
    probarCifraMayor(9, b, 9);
    probarCifraMayor(10, b, 1);
    probarCifraMayor(11, b, 1);
    probarCifraMayor(14, b, 4);
    int n = 100;
    while (n <= 1000000) {
        probarCifraMayor(n - 1, b, 9);
        probarCifraMayor(n, b, 1);
        probarCifraMayor(n + 1, b, 1);
        probarCifraMayor(n - 1 + (n / 2), b, 9);
        probarCifraMayor(n + (n / 2), b, 5);
        n = 10 * n;
    }
    // Pruebas en base 2
    probarCifraMayor(0, 2, 0);
    probarCifraMayor(1, 2, 1);
    probarCifraMayor(254, 2, 1);
    // Pruebas en base 8
    probarCifraMayor(0, 8, 0);
    probarCifraMayor(7, 8, 7);
    probarCifraMayor(8, 8, 1);
    probarCifraMayor(16, 8, 2);
}


// Pre:  <n> es el número natural y <b> está comprendido entre 2 y 10 y <laMasSignificativa>
//       es el valor de cifra más significativa de <n> cuando se escribe en base <b>
// Post: Informa si el valor devuelto al ejecutar cifraMasSignificativa(n, b) coincide
//       con el de <laMasSignificativa>, cuando <n> se escribe en base <b>
void probarCifraMasSignificativa(const int n, const int b, const int laMasSignificativa) {
    int m = cifraMasSignificativa(n, b);
    if (m == laMasSignificativa) {
        cout << "Ok. cifraMasSignificativa(" << n << "," << b << ") = " << m << endl;
    } else {
        cout << "Mal. cifraMasSignificativa(" << n << "," << b << ") = " << m << "  pero debiera ser "
             << laMasSignificativa << endl;
    }
}
// Función auxiliar para obtener la cifra más significativa de n
// en base b conociendo el número de cifras de n
int masSig(const int n, const int b) {
    int numDigitos = numCifras(n, b);
    return n / int(pow(b, numDigitos - 1));
}

// Prueba el comportamiento de cifraMasSignificativa(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMasSignificativa() {
   
    // Pruebas b=10
    int b = 10;
    int i = 1;
    while(i > 0 && i <= 2147483647) {
        probarCifraMasSignificativa(i - 1, b, masSig(i - 1, b));
        probarCifraMasSignificativa(i, b, masSig(i, b));
        probarCifraMasSignificativa(i + 1, b, masSig(i + 1, b));
        i = i * 5;
    }
    // Pruebas b=2
    b = 2;
    i = 1;
    while(i >= 0 && i <= 2147483647) {
        probarCifraMasSignificativa(i - 1, b, masSig(i - 1, b));
        probarCifraMasSignificativa(i, b, masSig(i, b));
        probarCifraMasSignificativa(i + 1, b, masSig(i + 1, b));
        i = i * 5;
    }
    // Pruebas b=8
    b = 8;
    i = 1;
    while(i >= 0 && i <= 2147483647) {
        probarCifraMasSignificativa(i - 1, b, masSig(i - 1, b));
        probarCifraMasSignificativa(i, b, masSig(i, b));
        probarCifraMasSignificativa(i + 1, b, masSig(i + 1, b));
        i = i * 5;
    }
}

// Función auxiliar para sumar las cifras de n en base b
// conociendo el número de cifras de n
int sumCif(const int n, const int b) {
    int numDigitos = numCifras(n, b);
    int s = 0;
    int m = n;
    for (unsigned i = 0; i < numDigitos; i++){
        s += m % b;
        m = m / b;
    }
    return s;
}
// Pre:  <n> es el número natural y <b> está comprendido entre 2 y 10 y <laSuma> es
//       el valor de las cifras de <n> cuando se escribe en base <b>
// Post: Informa si el valor devuelto al ejecutar sumaCifras(n, b) coincide
//       con el de <laSuma>, cuando <n> se escribe en base <b>
void probarSumaCifras(const int n, const int b, const int laSuma) {
    int m = sumaCifras(n, b);
    if (m == laSuma) {
        cout << "Ok. probarSumaCifras(" << n << "," << b << ") = " << m << endl;
    } else {
        cout << "Mal. probarSumaCifras(" << n << "," << b << ") = " << m << "  pero debiera ser "
             << laSuma << endl;
    }
}


// Prueba el comportamiento de probarSumaCifras(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarSumaCifras() {
    // Pruebas b=10
    int b = 10;
    int i = 1;
    while(i > 0 && i <= 2147483647) {
        probarSumaCifras(i - 1, b, sumCif(i - 1, b));
        probarSumaCifras(i, b, sumCif(i, b));
        probarSumaCifras(i + 1, b, sumCif(i + 1, b));
        i = i * 5;
    }
    // Pruebas b=2
    b = 2;
    i = 1;
    while(i > 0 && i <= 2147483647) {
        probarSumaCifras(i - 1, b, sumCif(i - 1, b));
        probarSumaCifras(i, b, sumCif(i, b));
        probarSumaCifras(i + 1, b, sumCif(i + 1, b));
        i = i * 5;
    }
    // Pruebas b=8
    b = 8;
    i = 1;
    while(i > 0 && i <= 2147483647) {
        probarSumaCifras(i - 1, b, sumCif(i - 1, b));
        probarSumaCifras(i, b, sumCif(i, b));
        probarSumaCifras(i + 1, b, sumCif(i + 1, b));
        i = i * 5;
    }
}


// Ejecuta una secuencia de pruebas de las funciones definidas
// en el módulo cálculos
int main() {
    // Pruebas del comportamiento de numCifras(n,b)
    probarNumCifras ();
    probarCifra();
    probarCifraMayor();
    probarCifraMasSignificativa();
    probarSumaCifras();
    // cout << "n para realizar las pruebas: ";
    // int n;
    // cin >> n;
    // cout << "numCifras: " << numCifras(n) << endl;
    // cout << "La cifra 2 de n " << cifra(n,2) << endl;
    // cout << "La cifra mayor de n es: " << cifraMayor(n) << endl;
    // cout << "La cifra más significativa de n: " << cifraMasSignificativa(n) << endl;
    // cout << "La suma de cifras: " << sumaCifras(n) << endl;
    // Pruebas del comportamiento de cifra(n,i,b)
    // Pruebas del comportamiento de cifraMayor(n,b)
    // Pruebas del comportamiento de cifraMasSignificativa(n,b)
    // Pruebas del comportamiento de sumaCifras(n,b)
    // Fin del programa de pruebas
    return 0;
}
