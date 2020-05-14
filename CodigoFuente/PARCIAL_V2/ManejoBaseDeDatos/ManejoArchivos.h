#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H

#include <string>
#include <fstream>

using namespace std;

class ManejoArchivos
{
public:
    ManejoArchivos();
    void leerArchivo(string nombreDeArchivo, string *contenido);
    void escribirArchivo(string nombreDeArchivo, string contenido);
};

#endif // MANEJOARCHIVOS_H
