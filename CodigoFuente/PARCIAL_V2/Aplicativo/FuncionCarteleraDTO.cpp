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

SalaDTO FuncionCarteleraDTO::getSala() const
{
    return sala;
}

void FuncionCarteleraDTO::setSala(const SalaDTO &value)
{
    sala = value;
}
