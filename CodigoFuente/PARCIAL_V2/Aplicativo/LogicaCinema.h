#ifndef LOGICACINEMA_H
#define LOGICACINEMA_H

#include <string>
#include <map>


using namespace std;

#define ADMIN   "admin"

class LogicaCinema
{
public:
    LogicaCinema();

    bool autenticarse(string nombre, string clave);
    bool esAdmin(string nombre);

    bool validarAciento(char fila, int  silla);
    bool comprarAsiento(char fila, int  silla);

    bool crearUsuario(string nombre, string password);
    bool recargarUsuario(string nombre,int valor);

    map<string,int> informeVentas(string dia);
    void modificarCartelera(int id, string nombrePelicula, string sala_hora, string duracion);
};

#endif // LOGICACINEMA_H
