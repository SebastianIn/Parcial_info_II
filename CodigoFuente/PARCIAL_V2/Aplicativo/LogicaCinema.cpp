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

map<string, int> LogicaCinema::informeVentas(string dia)
{
    map<string, int> ventas;
    ventas.insert(pair<string, int>("Funcion 1",200000));
    ventas.insert(pair<string, int>("Funcion 2",300000));
    ventas.insert(pair<string, int>("Funcion 3",400000));
    ventas.insert(pair<string, int>("Funcion 4",500000));
    ventas.insert(pair<string, int>("Funcion 5",600000));
    ventas.insert(pair<string, int>("Funcion 6",700000));
    ventas.insert(pair<string, int>("Funcion 7",800000));
    ventas.insert(pair<string, int>("Funcion 8",1000000));
    ventas.insert(pair<string, int>("Total",4500000));
    return ventas;
}

void LogicaCinema::modificarCartelera(int id, string nombrePelicula, string sala, string hora, string duracion)
{

}

list<FuncionCarteleraDTO> LogicaCinema::solictarCartelera()
{
    list<FuncionCarteleraDTO> cartelera;
    for(int i=0; i<8;i++){
        FuncionCarteleraDTO funcion;
        funcion.setId(i);
        funcion.setHora("4pm");
        funcion.setIdSala(to_string(i));
        funcion.setNombrePelicula("prueba");
        cartelera.push_back(funcion);
    }
    return cartelera;
}

SalaDTO LogicaCinema::consultarSala(int funcion)
{
    SalaDTO sala;
    sala.setIdFuncion(funcion);
    return sala;
}
