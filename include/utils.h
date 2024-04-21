/*
    Fichero donde se incluiran las funciones que pueden ser utilies para 
    la funcionalidad de la aplicación.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <libgen.h>

// Función que lee la API Key de un fichero aparte
std::string readAPIkeyFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string APIkey;

    if(file.is_open())
    {
        getline(file, APIkey);
        file.close();
    }
    else
    {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
    }

    return APIkey;
}

std::string getExecutablePath()
{
    char buffer[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        return std::string(buffer);
    } else {
        return ""; // Si no se puede obtener la ruta, devuelve una cadena vacía
    }
}

std::string getExecutableDirectory()
{
    char buffer[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        return std::string(dirname(buffer));
    } else {
        return ""; // Si no se puede obtener la ruta, devuelve una cadena vacía
    }
}