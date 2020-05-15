#ifndef FUNCIONCARTELERADTO_H
#define FUNCIONCARTELERADTO_H

#include "SalaDTO.h"

#include <string>

using namespace std;

class FuncionCarteleraDTO
{
public:
    FuncionCarteleraDTO();

    string getNombrePelicula() const;
    void setNombrePelicula(const string &value);

    int getId() const;
    void setId(int value);

    string getHora() const;
    void setHora(const string &value);

    SalaDTO getSala() const;
    void setSala(const SalaDTO &value);

private:
    int id;
    string nombrePelicula;
    string hora;
    SalaDTO sala;
};

#endif // FUNCIONCARTELERADTO_H
