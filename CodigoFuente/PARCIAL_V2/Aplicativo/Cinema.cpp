#include "Cinema.h"

Cinema::Cinema()
{

}

void Cinema::cicloAplicacion()
{
    bool correr = true;
    bool borrar = false;
    int opcion = 0;
    while (correr) {
        if(borrar){
            limpiarTerminal();
        }
        cout << "Ingrese 1 para login o 2 para cerrar: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            login();
            borrar = true;
            break;
        case 2:
            correr = false;
            borrar = true;
            break;
        default:
            cout << "Opcion " << opcion << " invalida" << endl;
            borrar = false;
            break;
        }

    }
}

void Cinema::menuAdmin()
{
    limpiarTerminal();
    cout << "Bienvenido Administrador" << endl;
    cout << "\t Menu de Admin " << endl;
}

void Cinema::rutinaUsuario(string nombre)
{
    limpiarTerminal();
    char basura;
    int funcion = 0;
    bool repetir = true;
    char fila = 'z';
    int  silla = 0;
    cout << "\t\tBienvenido " << nombre << endl;
    cout << endl;
    verCartelera();
    cout << "Nota: si se ingresa un id desconocido se aborta la compra." << endl;
    cout << "Ingrese Id de funcion: ";
    cin >> funcion;
    if(funcion > 8 or funcion < 1){
        cout << "Error!! funcion desconocida. ingrese cualquier valor para seguir." << endl;
        cin >> basura;
        return;
    }
    verSalaParaFuncion(funcion);
    cout << "Precios Asientos VibroSound: $ 15.000" << endl;
    cout << "Precios Asientos Generales:  $ 10.000" << endl;
    repetir = true;
    while (repetir) {
        cout << "Nota: filas, solo letras en Mayuscula de la /'A/' hasta la /'H/'" << endl;
        cout << "Ingrese la fila: ";
        cin >> fila;
        if(fila < 'A' || fila > 'H'){
            cout << "Error, fila " << fila << " invalida." << endl;
            cout << "se leccione una fila valida. " << endl;
        }else{
            repetir = false;
        }
    }
    repetir = true;
    while (repetir) {
        cout << "Nota: los asientos son nuemros enteros y van desde el 1 hasta el 20" << endl;
        cout << "Ingrese la numero de asiento: ";
        cin >> silla;
        if(silla < 1 || silla > 20){
            cout << "Error, silla numero " << silla << " no existe." << endl;
            cout << "se leccione un numero de asiento valido. " << endl;
        }else{
            repetir = false;
        }
    }
    if(!logica.validarAciento(fila,silla)){
        cout << "Error! El aciento seleccionado no es valido." << endl;
        cout << "Compra cancelada. Ingrese cualquier caracter y enter para continuar" << endl;
        cin >> basura;
        return;
    }
    if(!logica.comprarAsiento(fila,silla)){
        cout << "Error! No cuenta con suficiente dinero." << endl;
        cout << "Compra cancelada. Ingrese cualquier caracter y enter para continuar" << endl;
        cin >> basura;
        return;
    }
    cout << endl;
    cout << "Compra de asiento " << fila << silla << " fue un Exito!"<< endl;
    cout << "Ingrese cualquier caracter y enter para continuar." << endl;
    cin >> basura;
}

void Cinema::login()
{
    cout << endl;
    string nombre;
    string clave;
    bool admin;
    char basura;
    cout << "Ingrese nombre de usuario: ";
    cin >> nombre;
    cout << "Ingrese clave de acceso: ";
    cin >> clave;
    if(!logica.autenticarse(nombre,clave)){
        cout << "Error!! Usuario o clave incorrecta. oprima enter para seguir.";
        cin >> basura;
        return;
    }
    limpiarTerminal();
    admin = logica.esAdmin(nombre);
    if(admin){
        menuAdmin();
    }else{
        rutinaUsuario(nombre);
    }

}

void Cinema::ventaBoleta()
{

}

void Cinema::cargarSaldo()
{

}

void Cinema::crearUsuario()
{

}

void Cinema::informeVentasDelDia()
{

}

void Cinema::cambiarFuncion()
{

}

void Cinema::verCartelera()
{
    cout << "ver Cartelera" << endl;
}

void Cinema::verSalaParaFuncion(int idFuncion)
{
    cout << "sala de funcion" << endl;
}

void Cinema::limpiarTerminal()
{
    cout << string( 100, '\n' );
}


