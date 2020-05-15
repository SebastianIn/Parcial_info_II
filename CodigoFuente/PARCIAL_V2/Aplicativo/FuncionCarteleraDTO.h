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

    string getIdSala() const;
    void setIdSala(const string &value);

private:
    int id;
    string nombrePelicula;
    string hora;
    string idSala;
};

#endif // FUNCIONCARTELERADTO_H
