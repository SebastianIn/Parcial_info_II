#include "LogicaCinema.h"

LogicaCinema::LogicaCinema()
{

}

bool LogicaCinema::autenticarse(string nombre, string clave)
{
    return true;
}

bool LogicaCinema::esAdmin(string nombre)
{
    return nombre == ADMIN;
}

bool LogicaCinema::validarAciento(char fila, int silla)
{
    return true;
}

bool LogicaCinema::comprarAsiento(char fila, int silla)
{
    return true;
}

bool LogicaCinema::crearUsuario(string nombre, string password)
{
    return true;
}

bool LogicaCinema::recargarUsuario(string nombre, int valor)
{
    return true;
}
