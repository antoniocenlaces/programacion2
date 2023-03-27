#include <iostream>
#include <iomanip>
#include <ctime>
// #include <cstdlib>

using namespace std;
//Pre: r,r ∊ R ∧ r < s
//Post: randInt(r,s)= α ∧ α ∊ [r, s]
double randDouble(const double r, const double s) {
    return  double(rand()) / RAND_MAX * (s - r);
}

int main(int numArg, char* v[]) {
    if (numArg == 4){
        srand(time(nullptr));
        int numeros = atoi(v[1]);
        double inicial = atof(v[2]);
        double final = atof(v[3]);
        // cout << "De nuevo Numeros: " << numeros << " Inicial: " << inicial << " final: " << final << " args: " << numArg << endl;
        // cout << "Prueba de randInt " << randInt(inicial, final) << endl;
        unsigned i= 0;
        unsigned j = 0;
        while (i < numeros) {
            while(j < 10 && i < numeros) {
                cout << setw(9) << fixed << setprecision(3) << randDouble(inicial, final);
                j++;
                i++;
            }
            cout << endl;
            j = 0;
        }
        return 0;
    } else
    {
        return 1;
    }
}