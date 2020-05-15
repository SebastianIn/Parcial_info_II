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
        cout << "Ingrese 1 para login, 2 para crear Usuario o 3 para cerrar: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            login();
            borrar = true;
            break;
        case 2:
            crearUsuario();
            borrar = true;
            break;
        case 3:
            correr = false;
            borrar = true;
            break;
        default:
            cout << "Opcion " << opcion << " invalida" << endl;
            borrar = false;
            break;
        }
    }
    cout << "Exit" << endl;
}

void Cinema::menuAdmin(string nombre)
{
    int opcion = 0;
    char basura;
    limpiarTerminal();
    cout << "Bienvenido Administrador" << endl;
    cout << "\t\t Menu de Admin " << endl << endl;
    cout << "Seleccione una de las siguientes opciones: " << endl;
    cout << "\t 1 - Cargar Saldo Usuario." << endl;
    cout << "\t 2 - Generar Reporte de Venta del dia." << endl;
    cout << "\t 3 - Modificar Cartelera." << endl;
    cout << "\t 4 - Vender Boleta." << endl;
    cout << "Ingrese su eleccion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
        cargarSaldo();
        break;
    case 2:
        informeVentasDelDia();
        break;
    case 3:
        cambiarFuncion();
        break;
    case 4:
        ventaBoleta(nombre);
        break;
    default:
        cout << "Error! Opcion "<< opcion <<" no es una opcion valida." << endl;
        break;
    }
    cout << "Ingrese cualquier caracter y enter para continuar." << endl;
    cin >> basura;
}

void Cinema::login()
{
    limpiarTerminal();
    cout << "\t\t\t Login " << endl << endl;
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
        menuAdmin(nombre);
    }else{
        ventaBoleta(nombre);
    }

}

void Cinema::ventaBoleta(string nombre)
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
        cout << "Error!! funcion desconocida. ingrese cualquier caracter para seguir." << endl;
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

void Cinema::cargarSaldo()
{
    limpiarTerminal();
    string nombre;
    int valor;
    bool ok;
    cout << "\t\t Cargar Saldo A Usuarios" << endl;
    cout << "Ingrese cedula usaurio a recargar: ";
    cin >> nombre;
    cout << "Ingrese monto a recargar: ";
    cin >> valor;
    ok = logica.recargarUsuario(nombre,valor);
    if(ok){
        cout << "Recarga a " << nombre << " por valor de $" << valor << " Fue exitosa!" << endl;
    }else{
        cout << "Error! Recarga Fallida. " << endl;
    }
}

void Cinema::crearUsuario()
{
    limpiarTerminal();
    string nombre;
    string password;
    char basura;
    bool ok;
    cout << "\t\t Creacion de Usuarios" << endl;
    cout << endl << "Nota:"<< endl;
    cout << "Recuerde que la cedula sera su nombre de usuario." << endl;
    cout << "No ingrese espacios en blanco ni signos de puntuacion." << endl;
    cout << endl << endl;
    cout << "Ingrese cedula usaurio: ";
    cin >> nombre;
    cout << "Ingrese el nuevo password: ";
    cin >> password;
    ok = logica.crearUsuario(nombre,password);
    if(ok){
        cout << "Usuario " << nombre << " creado exitosamente!" << endl;
    }else{
        cout << "Error! Falla Al Crear Usuario. " << endl;
    }
    cout << "Ingrese cualquier caracter y enter para continuar." << endl;
    cin >> basura;
}

void Cinema::informeVentasDelDia()
{
    limpiarTerminal();
    cout << "\t\t informe de ventas del dia." << endl;
    time_t t = time(nullptr);
    char buf[11];
    strftime(buf, sizeof(buf), "%Y-%m-%d", localtime(&t));
    string fecha(buf);
    map<string,int> ventas = logica.informeVentas(fecha);
    cout << "fecha: " << fecha << endl;
    for(auto it = ventas.begin(); it != ventas.end(); it++){
        cout << "\t " << it->first << ": \t$" << it->second << endl;
    }
}

void Cinema::cambiarFuncion()
{
    int funcion;
    string nombrePelicula;
    string sala_hora;
    string sala;
    string hora;
    string duracion;
    limpiarTerminal();
    cout << "\t\t Edicion de Cartelera." << endl;
    verCartelera();
    cout << "Ingrese Id de funcion: ";
    cin >> funcion;
    if(funcion > 8 or funcion < 1){
        cout << "Error!! funcion desconocida." << endl;
        return;
    }
    cout << endl << "\t\t Solicitando nuevos parametros. " << endl;
    cout << "Ingrese nombrePelicula: ";
    cin >> nombrePelicula;
    cout << "Ingrese sala: ";
    cin >> sala;
    cout << "Ingrese hora: ";
    cin >> hora;
    cout << "Ingrese duracion: ";
    cin >> duracion;
    sala_hora = sala + "-" + hora;
    logica.modificarCartelera(funcion,nombrePelicula,sala_hora,duracion);
    cout << "Cambio Exitoso!!";
    verCartelera();
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


