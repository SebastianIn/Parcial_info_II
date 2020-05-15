#ifndef CINEMA_H
#define CINEMA_H

#include "LogicaCinema.h"
#include "Aplicativo/FuncionCarteleraDTO.h"
#include <map>
#include <list>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

/**
 * @brief The Cinema class Clase que se encaga de
 * las interfaces graficas con el usuario
 */
class Cinema
{
public:
    Cinema();
    void cicloAplicacion();
private:
    LogicaCinema logica;

    void menuAdmin(string nombre);
    void login();
    void ventaBoleta(string nombre);
    void cargarSaldo();
    void crearUsuario();
    void informeVentasDelDia();
    void cambiarFuncion();
    void verCartelera();
    void verSalaParaFuncion(int idFuncion);

    void limpiarTerminal();
    void ingresarBloque(string contenido, int longitud);
};

#endif // CINEMA_H
