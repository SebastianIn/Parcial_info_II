#ifndef CINEMA_H
#define CINEMA_H

/**
 * @brief The Cinema class Clase que se encaga de
 * las interfaces graficas con el usuario
 */
class Cinema
{
public:
    Cinema();
    void menu();
private:
    void ventaBoleta();
    void cargarSaldo();
    void crearUsuario();
    void informeVentasDelDia();
    void cambiarFuncion();
};

#endif // CINEMA_H
