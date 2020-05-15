#include <QCoreApplication>
#include "Aplicativo/Cinema.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Cinema cinema;
    cinema.cicloAplicacion();
    return a.exec();
}
