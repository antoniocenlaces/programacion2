#include <iostream>
#include "calculos.hpp"

using namespace std;

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: (n = 0 -> numCifras(n,b) = 1) ∧
//       (n > 0 -> numCifras(n,b) = NC ∧  n >= b^(NC-1) ∧ n < b^NC)
int numCifras(const int n, const int b) {
     if (n < b) {
        return 1;
    } else {
        return 1 + numCifras(n / b, b);
    }
}

// Pre:  n >= 0 ∧ i >= 1 ∧ 2 <= b <= 10
// Post: cifra(n,b,i) = (n / b^(i-1)) % b
int cifra(const int n, const int i, const int b) {
    if (i == 1) {
        return n % b;
    } else {
        return cifra(n / b, i-1, b);
    }
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMayor(n,b) = (Max α∊[1,∞].cifra(n,α,b))
int cifraMayor(const int n, const int b) {
    int elMayor = n % b; // Guardo el valor de la cifra menos significativa de n
    if (n < b) {
        return n; // Caso base
    } else {
        // Comparo el que guardé con el mayor de los que quedan
        int elMayorDeLosQueQuedan = cifraMayor(n / b, b); 
        return elMayorDeLosQueQuedan > elMayor ? elMayorDeLosQueQuedan : elMayor;
    }
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMasSignificativa(n) = n / b^(NC-1)
//       ∧ (n >= b^(NC-1) ∧ n < b^NC)
int cifraMasSignificativa(const int n, const int b) {
    if (n < b) {
        return n;
    } else {
        return cifraMasSignificativa(n / b, b);
    }
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: sumaCifras(n,b) = (∑ α∊[1,∞].cifra(n,α,b))
int sumaCifras(const int n, const int b) {
    if (n < b) {
        return n;
    } else {
        return (n % b) + sumaCifras(n / b, b);
    }
}