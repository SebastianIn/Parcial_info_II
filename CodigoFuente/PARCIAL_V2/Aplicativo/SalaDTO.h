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

    map<char, array<bool, 20> > getAcientos() const;
    void setAcientos(const map<char, array<bool, 20> > &value);

private:
    int acientosTotales;
    int acientosLibres;
    map<char,array<bool,20>> acientos;
    void inicializarAcientos();
    void calcularDisponibles();
};

#endif // SALADTO_H
