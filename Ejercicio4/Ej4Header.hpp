#ifndef Ej4_hpp
#define Ej4_hpp

#include <string>

/**
 * Función recursiva para comparar dos cadenas std::string en tiempo de ejecución.
 *
 * @param str1 Primera cadena a comparar.
 * @param str2 Segunda cadena a comparar.
 * @param index Índice actual para la comparación.
 * @return true si las cadenas son iguales, false en caso contrario.
 */
bool compare_strings(const std::string& str1, const std::string& str2, size_t index = 0);

/**
 * Función recursiva para comparar dos cadenas de tipo char* en tiempo de ejecución.
 *
 * @param str1 Primera cadena a comparar.
 * @param str2 Segunda cadena a comparar.
 * @return true si las cadenas son iguales, false en caso contrario.
 */
bool compare_char(const char* str1, const char* str2);

/**
 * Función constexpr para comparar dos cadenas de tipo char* en tiempo de compilación.
 *
 * @param str1 Primera cadena a comparar.
 * @param str2 Segunda cadena a comparar.
 * @return true si las cadenas son iguales, false en caso contrario.
 */
constexpr bool compare_constexpr(const char* str1, const char* str2);
#endif