#include "FuncionCarteleraDTO.h"

FuncionCarteleraDTO::FuncionCarteleraDTO()
{

}

string FuncionCarteleraDTO::getNombrePelicula() const
{
    return nombrePelicula;
}

void FuncionCarteleraDTO::setNombrePelicula(const string &value)
{
    nombrePelicula = value;
}

int FuncionCarteleraDTO::getId() const
{
    return id;
}

void FuncionCarteleraDTO::setId(int value)
{
    id = value;
}

string FuncionCarteleraDTO::getHora() const
{
    return hora;
}

void FuncionCarteleraDTO::setHora(const string &value)
{
    hora = value;
}

string FuncionCarteleraDTO::getIdSala() const
{
    return idSala;
}

void FuncionCarteleraDTO::setIdSala(const string &value)
{
    idSala = value;
}
