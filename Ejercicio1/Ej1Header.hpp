#ifndef Ej3_hpp
#define Ej3_hpp

#include <vector>

using matrix = std::vector<std::vector<int>>;

/**
 * Crea una matriz cuadrada de tamaño n x n y la llena con valores secuenciales.
 *
 * @param n Tamaño de la matriz (n x n).
 * @return Matriz cuadrada de tamaño n x n llena con valores secuenciales.
 */
matrix create_matrix(int n);

/**
 * Imprime una matriz cuadrada en orden inverso (de abajo hacia arriba y de derecha a izquierda).
 *
 * @param M Matriz cuadrada a imprimir.
 */
void print_matrix(matrix M);

#endif