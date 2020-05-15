#ifndef LOGICACINEMA_H
#define LOGICACINEMA_H

#include "Aplicativo/FuncionCarteleraDTO.h"
#include "ManejoBaseDeDatos/BaseDeDatos.h"
#include <string>
#include <map>
#include <list>


using namespace std;

#define ADMIN   "admin"

class LogicaCinema
{
public:
    LogicaCinema();

    /**
     * @brief autenticarse - Metodo de autenticacion
     * @param nombre - nombre de usuario
     * @param clave - password de asceso
     * @return true si esta autorizado, false en caso contrario
     */
    bool autenticarse(string nombre, string clave);

    int consultarSaldo(string nombre);
    /**
     * @brief esAdmin - Metodo que indica si un usuario es administrador.
     * @param nombre - nombre de usuario
     * @return true si el usuario es administrador, false en caso contrario
     */
    bool esAdmin(string nombre);

    /**
     * @brief validarAciento - metodo que valida si un asiento esta
     * disponible.
     * @param funcion - funcion a la que se compra.
     * @param fila - fila del asiento.
     * @param silla - numero de silla del asiento.
     * @return true si el asiento esta disponible, false en caso contrario
     */
    bool validarAciento(int funcion, char fila, int  silla);
    /**
     * @brief comprarAsiento - metodo para comprar un asciento,
     * @param funcion - funcion a la que se compra.
     * @param fila - fila del asiento.
     * @param silla - numero de silla del asient
     * @return true si la compra fue exitosa, false encaso cotntrario.
     */
    bool comprarAsiento(int funcion, char fila, int  silla);

    /**
     * @brief crearUsuario -metodo de creacion de usuarios.
     * @param nombre - nombre de usuario
     * @param clave - password de asceso
     * @return creacion fue exitosa.
     */
    bool crearUsuario(string nombre, string password);
    /**
     * @brief recargarUsuario -metodo para recargar el saldo de un usuario.
     * @param nombre - nombre de usuario
     * @param valor - Valor a recargar.
     * @return true recarga exitos, false en caso de error.
     */
    bool recargarUsuario(string nombre,int valor);

    /**
     * @brief informeVentas Metodo que entrega un informe de ventas del dia.
     * @param dia - dia del informe.
     * @return map<string,int> dode se entuentra la funcion contra el monto vendido
     * para cada funcion.
     */
    map<string,int> informeVentas(string dia);
    /**
     * @brief modificarCartelera - Metodo para modificar la cartelera.
     * @param id
     * @param nombrePelicula
     * @param sala
     * @param hora
     * @param duracion
     */
    void modificarCartelera(int id, string nombrePelicula, string sala, string hora, string duracion);

    /**
     * @brief solictarCartelera Metodo que solicita la cartelera actual.
     * @return lista funciones FuncionCarteleraDTO.
     */
    list<FuncionCarteleraDTO> solictarCartelera();

    /**
     * @brief consultarSala Metodo para consultar una sala.
     * @param funcion - id de la funcion.
     * @return SalaDTO con la info del estado de la sala.
     */
    SalaDTO consultarSala(int funcion);

private:
    BaseDeDatos bd;

};

#endif // LOGICACINEMA_H
