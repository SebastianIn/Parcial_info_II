#include "ManejoArchivos.h"

ManejoArchivos::ManejoArchivos()
{

}

void ManejoArchivos::leerArchivo(string nombreDeArchivo, string *contenido)
{
    ifstream archivo(nombreDeArchivo);
    string textoLinea,texto = "";
    while (!archivo.eof()) {
        getline(archivo,textoLinea);
        texto += textoLinea;
    }
    *contenido = texto;
    archivo.close();
}

void ManejoArchivos::escribirArchivo(string nombreDeArchivo, string contenido)
{
    ofstream archivo(nombreDeArchivo);
    archivo<<contenido;
    archivo.close();
}

