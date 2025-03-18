#include <iostream>
#include <string>

#include "Ej4Header.hpp"

bool compare_strings(const std::string& str1, const std::string& str2, size_t index = 0) {
    // Si ambos strings llegaron al final al mismo tiempo, son iguales
    if (index == str1.length() && index == str2.length()) return true;

    // Si los caracteres en la posición actual son distintos, los strings no son iguales
    if (str1[index] != str2[index]) return false;

    // Llamada recursiva incrementando el índice para comparar el siguiente carácter
    return compare_strings(str1, str2, index + 1);
}

bool compare_char(const char* str1, const char* str2) {
    // Si ambos punteros llegaron al carácter nulo ('\0'), las cadenas son iguales
    if (*str1 == '\0' && *str2 == '\0') return true;

    // Si los caracteres en la posición actual son distintos, las cadenas no son iguales
    if (*str1 != *str2) return false;

    // Llamada recursiva avanzando los punteros al siguiente carácter
    return compare_char(str1 + 1, str2 + 1);
}