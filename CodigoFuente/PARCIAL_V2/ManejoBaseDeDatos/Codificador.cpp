#include "Codificador.h"

Codificador::Codificador(unsigned long semillaP)
{
    semilla = semillaP;
}

string Codificador::codificar(string textoOriginal)
{
    string textoBinario = string2bin(textoOriginal);
    string codificado = "";
    string bloque = "";
    string bloqueCodificado = "";
    unsigned long posicion = 0;
    unsigned long longitud = textoBinario.length();
    unsigned long numeroDeBloques = longitud / semilla;
    for(unsigned int i = 0; i < numeroDeBloques; i++){
        bloque = textoBinario.substr(posicion,semilla);
        posicion += semilla;
        bloqueCodificado = correrBloque(bloque);
        codificado.append(bloqueCodificado);
    }
    if(longitud % semilla != 0){
        unsigned long faltante = longitud % semilla;
        bloque = textoBinario.substr(posicion,faltante);
        bloqueCodificado = correrBloque(bloque);
        codificado.append(bloqueCodificado);
    }
    return bin2String(codificado);
}

string Codificador::decodificar(string textoCodificado)
{
    string textoBinario = string2bin(textoCodificado);
    string decodificado = "";
    string bloque = "";
    string bloqueDecodificado = "";
    unsigned long posicion = 0;
    unsigned long longitud = textoBinario.length();
    unsigned long numeroDeBloques = longitud / semilla;
    for(unsigned int i = 0; i < numeroDeBloques; i++){
        bloque = textoBinario.substr(posicion,semilla);
        posicion += semilla;
        bloqueDecodificado = devolverBloque(bloque);
        decodificado.append(bloqueDecodificado);
    }
    if(longitud % semilla != 0){
        unsigned long faltante = longitud % semilla;
        bloque = textoBinario.substr(posicion,faltante);
        bloqueDecodificado = devolverBloque(bloque);
        decodificado.append(bloqueDecodificado);
    }
    return bin2String(decodificado);
}

string Codificador::string2bin(string texto)
{
    string binario = "";
    unsigned int letra;
    for (unsigned int i=0; i<texto.length(); i++) {
        string binLetra[8];
        letra = static_cast<unsigned int>(texto[i]);
        for (int j=7;j>=0;j--) {
            binLetra[j]=static_cast<char>(letra%2+48);
            letra/=2;
        }
        for(int j=0; j<8; j++){
            binario += binLetra[j];
        }
    }
    return binario;
}

string Codificador::bin2String(string texto)
{
    string conversion = "";
    unsigned long longitud = texto.size();
    unsigned long cantidadDeCaracteres = longitud / 8;
    unsigned long index=0;
    unsigned long numero=0;
    for(unsigned long i=0; i < cantidadDeCaracteres; i++){
        numero=0;
        index=8*i;
        for(unsigned long j=0;j<8;j++){
            if(texto[j+index] == '1'){
               numero += static_cast<unsigned long>(pow(2,(7-j)));
            }
        }
        conversion.push_back(static_cast<char>(numero));//[i] = static_cast<char>(numero);
    }
    return conversion;
}

string Codificador::correrBloque(string bloque)
{
    char primero = bloque.back();
    unsigned long longituf = bloque.length();
    for(unsigned long i = longituf - 1; i > 0; i--){
         bloque[i] = bloque[i-1];
    }
    bloque[0] = primero;
    return bloque;
}

string Codificador::devolverBloque(string bloque)
{
    char ultimo = bloque.front();
    unsigned long ultimoPos = bloque.length() - 1;
    for(unsigned long i = 0; i < ultimoPos; i++){
         bloque[i] = bloque[i+1];
    }
    bloque[ultimoPos] = ultimo;
    return bloque;
}
