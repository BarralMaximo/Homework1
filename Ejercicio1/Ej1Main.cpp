#include <iostream>

#include "Ej1Header.hpp"

using namespace std;

int main(){
    int n = 0;

    cout << "Ejercicio 1 - Creación e impresión de matriz \n Por favor inserte un valor n: ";

    cin >> n;

    if (cin.fail()) {
        cout << "Entrada inválida. Debes ingresar un número." << endl;
        cin.clear();
    }

    print_matrix(create_matrix(n));
    return 0;
}
