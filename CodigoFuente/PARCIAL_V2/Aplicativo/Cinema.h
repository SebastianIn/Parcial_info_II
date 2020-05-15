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
    /**
     * @brief cicloAplicacion Metodo Principal
     */
    void cicloAplicacion();
private:
    /**
     * @brief logica Clase con la logica de fondo.
     */
    LogicaCinema logica;

    /**
     * @brief menuAdmin Metodo que de menu para
     * el administrador.
     * @param nombre - nombre del usuario.
     */
    void menuAdmin(string nombre);
    /**
     * @brief login Metodo donde se ejecuta la
     * interfaz de login.
     */
    void login();
    /**
     * @brief ventaBoleta - Menu de venta de boletas.
     * @param nombre - nombre del usuario.
     */
    void ventaBoleta(string nombre);
    /**
     * @brief cargarSaldo - interfaz de Carga de saldo
     */
    void cargarSaldo();
    /**
     * @brief crearUsuario - interfaz de creacion de usuario
     */
    void crearUsuario();
    /**
     * @brief informeVentasDelDia - interfaz de Informe ventas.
     */
    void informeVentasDelDia();
    /**
     * @brief cambiarFuncion - Interfaz para modificacion de cartelera.
     */
    void cambiarFuncion();
    /**
     * @brief verCartelera - Interfaz que muestra la cartelera.
     */
    void verCartelera();
    /**
     * @brief verSalaParaFuncion - Interfaz que muestra el estado
     * de la sala.
     * @param idFuncion - id de la funcion a la que corresponde la sala.
     */
    void verSalaParaFuncion(int idFuncion);

    void limpiarTerminal();
    /**
     * @brief ingresarBloque - Metodo para imprimir un bloque de longitud
     * constante.
     * @param contenido - contenido a mostrar.
     * @param longitud - longitud del bloque.
     */
    void ingresarBloque(string contenido, int longitud);


};

#endif // CINEMA_H
