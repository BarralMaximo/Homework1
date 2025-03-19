#ifndef LOG_SYSTEM_HPP
#define LOG_SYSTEM_HPP

#include <string>

using namespace std;

/// Enumeración para los niveles de severidad en el log.
enum sevlev {DEBUG, INFO, WARNING, ERROR, CRITICAL};

/**
 * @brief Obtiene la etiqueta de severidad en formato string.
 * 
 * @param level Nivel de severidad (DEBUG, INFO, WARNING, ERROR, CRITICAL).
 * @return string Representación en texto del nivel de severidad.
 */
string get_severity(sevlev level);

/**
 * @brief Registra un mensaje en el archivo de log con un nivel de severidad específico.
 * 
 * @param msg Mensaje a registrar.
 * @param level Nivel de severidad del mensaje.
 */
void logMessage(const string& msg, sevlev level);

/**
 * @brief Registra un error con detalles adicionales como el archivo y la línea de código donde ocurrió.
 * 
 * @param msg_error Descripción del error.
 * @param file Nombre del archivo donde ocurrió el error.
 * @param codeline Número de línea donde se produjo el error.
 */
void logMessage(string msg_error, string file, int codeline);

/**
 * @brief Registra eventos de acceso de usuario con una etiqueta de seguridad.
 * 
 * @param msg_access Mensaje de acceso (Ejemplo: "Access Granted", "Access Denied").
 * @param username Nombre del usuario que intentó acceder.
 */
void logMessage(const string& msg_access, const string& username);

#endif