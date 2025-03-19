#include <iostream>
#include <cstring>

#include "Ej4Header.hpp"

using namespace std;

int main() {
    const int MAX_LENGTH = 100; // Tamaño máximo de las cadenas
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    cout << "Ingrese la primera cadena: ";
    cin.getline(str1, MAX_LENGTH);

    cout << "Ingrese la segunda cadena: ";
    cin.getline(str2, MAX_LENGTH);

    if (compare_char(str1, str2)) {
        cout << "Las cadenas son iguales.\n";
    } else {
        cout << "Las cadenas son diferentes.\n";
    }

    return 0;
}
