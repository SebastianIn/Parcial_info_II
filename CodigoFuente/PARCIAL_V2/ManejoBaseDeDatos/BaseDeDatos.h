#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include "Codificador.h"
#include "ManejoArchivos.h"
#include <cstring>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <array>
#include <sstream>

using namespace std;

class BaseDeDatos
{
public:
    BaseDeDatos();
    ~BaseDeDatos();
    /**************************************************************
     *
     *          Metodos para la manipulacion de Usuarios
     *
     *************************************************************/

    bool AutenticarUsuario(string nombre, string clave);
    bool AutenticarAdmin(string clave);
    bool crearUsuario(string nombre, string clave);
    bool cargarUsuario(string nombre, int valor);
    int saldoUsuario(string nombre);

    /**************************************************************
     *
     *          Metodos para la manipulacion de salas
     *
     *************************************************************/

    map<char,array<bool,20>> consultarEstadoSalaDeCine(int sala);
    void cambiarEstadoSala(map<char,array<bool,20>> nuevoEstado,int sala);

    /**************************************************************
     *
     *          Metodos para el manejo de la cartelera.
     *
     *************************************************************/
    /**
     * @brief verCartelera metodo para solicitar la cartelera
     * @return lista con array<string , 5> que contiene los datos
     * id,nombre,genero,duracion,sala/hora,
     */
    list<array<string , 5>> verCartelera();
    void eliminarPelicula(string id);
    void agregarPelicula(array<string , 5> pelicula);

    /**************************************************************
     *
     *          Metodos para el manejo de la cartelera.
     *
     *************************************************************/
    /**
     * @brief consultarVentas consulta la tabla de ventas del dia
     * @param dia - dia a consultar con dormato dd-MM-YYYY
     * @return mapa con <idPelicula, valor>
     */
    vector<pair<string,string>> consultarVentas(string dia);
    void agregarVenta(string dia, string valor, string pelicula);

    /**************************************************************
     *
     *          Metodos para Manejo de precios.
     *
     *************************************************************/
    /**
      * @brief verPrecios consulta la tabla de precios
      * @return mapa con <idTipo,pair<nombre,valor>>
      */
     map<string,pair<string,string>> verPrecios();
     void agregarTipoPrecio(string idTipo,string nombre, string valor);
     void eliminarTipoPrecio(string idTipo);
     void modificarPrecio(string idTipo, string valor);

private:
    Codificador* codificador;
    ManejoArchivos* archivos;

    string obtenerContenido(string nombreArchivo);
    bool guardarDatos(string archivoDestino, string contenido);
};

#endif // BASEDEDATOS_H
