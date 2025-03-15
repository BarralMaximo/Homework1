#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<int>>;

/**
 * Crea una matriz cuadrada de tamaño n x n y la llena con valores secuenciales.
 *
 * @param n Tamaño de la matriz (n x n).
 * @return Matriz cuadrada de tamaño n x n llena con valores secuenciales.
 */
matrix create_matrix(int n) {
    matrix M(n, vector<int>(n));
    int cont = 1;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = cont;
            cont++;
        }
    }
    return M;
}

/**
 * Imprime una matriz cuadrada en orden inverso (de abajo hacia arriba y de derecha a izquierda).
 *
 * @param M Matriz cuadrada a imprimir.
 */
void print_matrix(matrix M){
    size_t size = M.size();
    int row = size;
    int column = size - 1;

    for(int i = (size*size); i != 0; i--) {
        if (i % size == 0){row -= 1; column = size -1;}
        
        cout << "M[" << row << "][" << column << "] = " << M[row][column] << endl;

        column -= 1;
    }
}


int main(){
    int n = 0;

    cout << "Ejercicio 1 - Creación e impresión de matriz" << endl << "Por favor inserte un valor n: ";

    cin >> n;

    if (cin.fail()) {
        cout << "Entrada inválida. Debes ingresar un número." << endl;
        cin.clear();
    }

    print_matrix(create_matrix(n));
    return 0;
}