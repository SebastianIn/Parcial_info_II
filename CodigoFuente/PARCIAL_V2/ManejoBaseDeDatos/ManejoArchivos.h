#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H

#include <string>
#include <fstream>

using namespace std;

class ManejoArchivos
{
public:
    ManejoArchivos();
    /**
     * @brief leerArchivo - Metodo para leer el contenido de un archivo
     * @param nombreDeArchivo - Nombre del archivo a leer.
     * @param contenido - apuntador donde se colocara el contnido leido
     */
    void leerArchivo(string nombreDeArchivo, string *contenido);
    /**
     * @brief escribirArchivo - Metodo para escribir el contenido de un archivo
     * @param nombreDeArchivo - Nombre del archivo a escribir.
     * @param contenido - contenido a escribir en el archivo.
     */
    void escribirArchivo(string nombreDeArchivo, string contenido);
};

#endif // MANEJOARCHIVOS_H
