#include <iostream>
#include <fstream>
#include <string>

#include "Ej2Header.hpp"

using namespace std;

// Función para obtener la etiqueta de severidad como string
string get_severity(sevlev level) {
    switch (level) {
        case DEBUG: return "[DEBUG]";
        case INFO: return "[INFO]";
        case WARNING: return "[WARNING]";
        case ERROR: return "[ERROR]";
        case CRITICAL: return "[CRITICAL]";
        default: return "[UNKNOWN]";
    }
}

void logMessage (const string& msg, sevlev level){
    ofstream logFile("log.txt", ios::app); // Modo append para no sobrescribir el archivo

    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }

    logFile << get_severity(level) << " " << msg << endl;
    logFile.close();
}

void logMessage(string msg_error, string file, int codeline){
    ofstream logFile("log.txt", ios::app);

    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }

    logFile << "[ERROR] " << msg_error << " (Archivo: " << file << ", Línea: " << codeline << ")" << endl;
    logFile.close();
}

void logMessage(const string& msg_access, const string& username){
    ofstream logFile("log.txt", ios::app);

    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }

    logFile << "[SECURITY] " << msg_access << " (Usuario: " << username << ")" << endl;
    logFile.close();
}