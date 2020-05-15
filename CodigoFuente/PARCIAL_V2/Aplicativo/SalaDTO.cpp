#include "SalaDTO.h"

SalaDTO::SalaDTO(int totales)
{
    acientosTotales = totales;
    acientosLibres = acientosTotales;
    inicializarAcientos();
}

int SalaDTO::getAcientosTotales() const
{
    return acientosTotales;
}

int SalaDTO::getAcientosLibres() const
{
    return acientosLibres;
}

map<char, array<bool, 20> > SalaDTO::getAcientos() const
{
    return acientos;
}

void SalaDTO::setAcientos(const map<char, array<bool, 20> > &value)
{
    acientos.clear();
    acientos = value;
}

int SalaDTO::getIdFuncion() const
{
    return idFuncion;
}

void SalaDTO::setIdFuncion(int value)
{
    idFuncion = value;
}

void SalaDTO::inicializarAcientos(){
    acientos.clear();
    for(char i=0; i < 8 ; i++){
        char fila = 'A' + i;
        array<bool,20> sillas;
        sillas.fill(true);
        acientos.insert(pair<char,array<bool,20>>(fila,sillas));
    }
}

void SalaDTO::calcularDisponibles()
{
    int disponibles = 0;
    for(auto it=acientos.begin(); it != acientos.end(); it++){
        for(auto its=it->second.begin(); its != it->second.end(); its++){
            if(*its){
                disponibles++;
            }
        }
    }
    acientosLibres = disponibles;
}

