#ifndef SALADTO_H
#define SALADTO_H

#include <map>
#include <array>

using namespace std;

class SalaDTO
{
public:
    SalaDTO(int totales = 160);
    int getAcientosTotales() const;
    int getAcientosLibres() const;

    /**
     * @brief getAcientos obtinen el mapa de la sala
     * @return mapa <fila, array<libre,silla>>
     */
    map<char, array<bool, 20> > getAcientos() const;
    /**
     * @brief setAcientos llena el mapa de la sala.
     * @param value - mapa <fila, array<libre,silla>>
     */
    void setAcientos(const map<char, array<bool, 20> > &value);

    int getIdFuncion() const;
    void setIdFuncion(int value);

private:
    int idFuncion;
    int acientosTotales;
    int acientosLibres;
    map<char,array<bool,20>> acientos;
    void inicializarAcientos();
    void calcularDisponibles();
};

#endif // SALADTO_H
