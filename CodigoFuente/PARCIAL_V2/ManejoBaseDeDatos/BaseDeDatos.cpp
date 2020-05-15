#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos()
{
    codificador = new Codificador();
    archivos = new ManejoArchivos();
}

BaseDeDatos::~BaseDeDatos()
{
    delete codificador;
    delete archivos;
}

bool BaseDeDatos::AutenticarUsuario(string nombre, string clave)
{
    string nombreArchivo = "bd/" + nombre +".txt";
    string contenido = obtenerContenido(nombreArchivo);
    size_t separador = contenido.find('@');
    string claveCod = contenido.substr(0,separador);
    return clave == claveCod;
}

bool BaseDeDatos::AutenticarAdmin(string clave)
{
    string admin = "bd/admin.txt";
    string claveLeida = obtenerContenido(admin);
    return claveLeida == clave;
}

bool BaseDeDatos::crearUsuario(string nombre, string clave)
{
    string nombreArchivo = "bd/" + nombre +  ".txt";
    string aIngresar = clave + "@" + "0";
    return guardarDatos(nombreArchivo,aIngresar);
}



bool BaseDeDatos::cargarUsuario(string nombre, int valor)
{
    string nombreArchivo = "bd/" + nombre +  ".txt";
    string contenido = obtenerContenido(nombreArchivo);
    size_t separador = contenido.find('@');
    string claveCod = contenido.substr(0,separador);
    string nuevoSaldo = to_string(valor);
    string aIngresar = claveCod + "@" + nuevoSaldo;
    return guardarDatos(nombreArchivo,aIngresar);
}

int BaseDeDatos::saldoUsuario(string nombre)
{
    string nombreArchivo = "bd/" + nombre +  ".txt";
    string contenido = obtenerContenido(nombreArchivo);
    size_t separador = contenido.find('@');
    string saldo = contenido.substr(separador+1);
    stringstream geek(saldo);
    int saldoInt;
    geek >> saldoInt;
    return saldoInt;
}

map<char, pair<int, bool> > BaseDeDatos::consultarEstadoSalaDeCine(int sala)
{
    map<char, pair<int, bool> > estadoActual;

    return estadoActual;
}

void BaseDeDatos::cambiarEstadoSala(map<char, pair<int, bool> > nuevoEstado)
{

}

list<array<string, 5> > BaseDeDatos::verCartelera()
{
    list<array<string, 5> >  cartelera;

    return cartelera;
}

void BaseDeDatos::eliminarPelicula(string id)
{

}

void BaseDeDatos::agregarPelicula(array<string, 5> pelicula)
{

}

vector<pair<string, string> > BaseDeDatos::consultarVentas(string dia)
{
    vector<pair<string, string> > ventas;
    ventas.push_back(pair<string,string> ("1","10000"));
    ventas.push_back(pair<string,string> ("2","15000"));
    ventas.push_back(pair<string,string> ("3","10000"));
    ventas.push_back(pair<string,string> ("4","15000"));
    //TODO
    return ventas;
}

void BaseDeDatos::agregarVenta(string dia, string valor, string pelicula)
{

}

map<string, pair<string, string> > BaseDeDatos::verPrecios()
{
    map<string,pair<string,string>> tablaPrecios;
    pair<string,string> tipoPrecio;
    tipoPrecio.first = "General";
    tipoPrecio.second = "10000";
    tablaPrecios.insert(pair<string,pair<string,string>>("1",tipoPrecio));
    tipoPrecio.first = "VIP";
    tipoPrecio.second = "15000";
    tablaPrecios.insert(pair<string,pair<string,string>>("2",tipoPrecio));
    //TODO
    return tablaPrecios;
}

void BaseDeDatos::agregarTipoPrecio(string idTipo, string nombre, string valor)
{

}

void BaseDeDatos::eliminarTipoPrecio(string idTipo)
{

}

void BaseDeDatos::modificarPrecio(string idTipo, string valor)
{

}

string BaseDeDatos::obtenerContenido(string nombreArchivo)
{
    string contenidoOriginal = "";
    string contenidoDecodificado = "";
    archivos->leerArchivo(nombreArchivo,&contenidoOriginal);
    contenidoDecodificado = codificador->decodificar(contenidoOriginal);
    return contenidoDecodificado;
}

bool BaseDeDatos::guardarDatos(string archivoDestino, string contenido)
{
    string contenidoCodificado = codificador->codificar(contenido);
    archivos->escribirArchivo(archivoDestino,contenidoCodificado);
    return true;
}



