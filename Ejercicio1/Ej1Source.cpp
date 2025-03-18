#include <iostream>
#include <vector>

#include "Ej1Header.hpp"

using namespace std;

matrix create_matrix(int n) {
    matrix M(n, vector<int>(n)); // Se inicializa una matriz de n x n con valores por defecto
    int cont = 1; // Contador para asignar valores secuenciales

    //Recorro la matriz barriendo las columnas de cada fila y actualizo el valor de cada posición de acuerdo al valor de cont
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = cont;
            cont++;
        }
    }
    return M;
}

void print_matrix(matrix M){
    size_t size = M.size();
    int row = size;
    int column = size - 1;

    //Recorro todos los elementos de la matriz del final al principio
    for(int i = (size * size); i != 0; i--) { 
        //Cuando llego al final de cada fila, me muevo a la fila anterior y reinicio el valor de las columnas al final de la fila
        if (i % size == 0){
            row -= 1;
            column = size - 1;
        }
        
        cout << "M[" << row << "][" << column << "] = " << M[row][column] << endl; // Imprime el valor actual

        column -= 1; // Mueve la columna a la izquierda
    }
}