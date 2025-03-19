#include <iostream>

#include "Ej2Header.hpp"

using namespace std;

int main(){
    // Registro de mensajes de diferentes niveles
    logMessage("Este es un mensaje de depuración.", DEBUG);
    logMessage("El sistema ha iniciado correctamente.", INFO);
    logMessage("Advertencia: Uso alto de memoria.", WARNING);
    logMessage("Error al acceder a la base de datos.", ERROR);
    logMessage("¡Fallo crítico en el sistema!", CRITICAL);

    // Registro de un error con detalles de archivo y línea
    logMessage("División por cero detectada", __FILE__, __LINE__);

    // Registro de eventos de seguridad
    logMessage("Access Granted", "admin");
    logMessage("Access Denied", "guest");

    // Simulación de un error crítico en tiempo de ejecución
    try {
        throw runtime_error("Error inesperado en la aplicación.");
    } catch (const exception& e) {
        logMessage(e.what(), __FILE__, __LINE__);
        cerr << "Error crítico detectado. Terminando ejecución." << endl;
        return 1;
    }

    cout << "Mensajes registrados en log.txt" << endl;
    return 0;
}