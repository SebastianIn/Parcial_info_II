#ifndef LOGICACINEMA_H
#define LOGICACINEMA_H

#include <string>

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
};

#endif // LOGICACINEMA_H
