#include <iostream>
#include <chrono>
#include <string>

#include "Ej4.hpp"

using namespace std;

bool compare_strings(const string& str1, const string& str2, size_t index = 0) {
    if (index == str1.length() && index == str2.length()) return true;

    if (str1[index] != str2[index]) return false;

    return compare_strings(str1, str2, index + 1);
}

bool compare_char(const char* str1, const char* str2) {
    if (*str1 == '\0' && *str2 == '\0') return true;

    if (*str1 != *str2) return false;

    return compare_char(str1 + 1, str2 + 1);
}

constexpr bool compare_constexpr(const char* str1, const char* str2) {
    if (*str1 == '\0' && *str2 == '\0') {return true;}

    if (*str1 != *str2) {return false;}

    return compare_constexpr(str1 + 1, str2 + 1);
}

int main() {
    string str1 = "Este es un texto de ejemplo con más de 64 caracteres para demostrar la funcionalidad de la función.";
    string str2 = "Este es un texto de ejemplo con más de 64 caracteres para demostrar la funcionalidad de la función.";

    const char* char1 = "Este es un texto de ejemplo con más de 64 caracteres para demostrar la funcionalidad de la función.";
    const char* char2 = "Este es un texto de ejemplo con más de 64 caracteres para demostrar la funcionalidad de la función.";

    auto start_time = chrono::high_resolution_clock::now();
    bool result = compare_strings(str1, str2);
    auto end_time = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    cout << "A compare_strings le tomó: " << elapsed_time.count() << " nanosegundos" << endl;
    cout << "Resultado de compare_strings: " << boolalpha << result << endl << endl;

    start_time = chrono::high_resolution_clock::now();
    result = compare_char(char1, char2);
    end_time = chrono::high_resolution_clock::now();
    elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    cout << "A compare_char le tomó: " << elapsed_time.count() << " nanosegundos" << endl;
    cout << "Resultado de compare_char: " << boolalpha << result << endl << endl;

    constexpr const char* const_text1 = "Este es un texto de ejemplo con más de 64 caracteres para demostrar la funcionalidad de la función.";
    constexpr const char* const_text2 = "Este es un texto de ejemplo con más de 64 caracteres para demostrar la funcionalidad de la función.";

    constexpr bool constexpr_result = compare_constexpr(const_text1, const_text2);

    cout << "A compare_constexpr le tomó: 0 nanosegundos (evaluado en tiempo de compilación)" << endl;
    cout << "Resultado de compare_constexpr: " << boolalpha << constexpr_result << endl << endl;
    
    /*CONCLUSIONES
    Los resultados muestran diferencias significativas en los tiempos de ejecución entre las distintas implementaciones de la comparación de cadenas:
    - constexpr es la opción más eficiente cuando se trabaja con datos constantes conocidos en tiempo de compilación, 
    ya que evita completamente la ejecución de código.

    - Para datos en tiempo de ejecución, char* ofrece un mejor rendimiento que std::string en este tipo de comparación. Imagino que esto se debe al manejo
    interno que hace std::string que aumenta la cantidad de código a ejecutar y por ende su duración.
    */

    cout << "Los resultados muestran diferencias significativas en los tiempos de ejecución entre las distintas implementaciones de la comparación de cadenas:\n";
    cout << "- constexpr es la opción más eficiente cuando se trabaja con datos constantes conocidos en tiempo de compilación,\n";
    cout << "ya que evita completamente la ejecución de código.\n\n";
    cout << "- Para datos en tiempo de ejecución, char* ofrece un mejor rendimiento que std::string en este tipo de comparación. Imagino que esto se debe al manejo\n";
    cout << "interno que hace std::string que aumenta la cantidad de código a ejecutar y por ende su duración.\n";

    return 0;
}