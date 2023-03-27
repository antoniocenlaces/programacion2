#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int numArg, char* v[]) {
    time_t t1,t2;
    int n = atoi(v[1]);
    for (unsigned i=0; i < n; i++) {
        cout << i + 1 << ") Pulse la tecla de fin de línea, por favor ...";
        t1 = time(nullptr);
       
           cin.get();
        
        t2 = time(nullptr);
        int segundos = int(t2 - t1);
        cout << "Su tiempo de reacción ha sido de " << segundos << " segundos" << endl;
        cout << endl;
    }
    return 0;
}