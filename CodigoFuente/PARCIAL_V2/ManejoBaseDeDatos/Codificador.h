#ifndef CODIFICADOR_H
#define CODIFICADOR_H

#include <string>
#include <math.h>

using namespace std;

/**
 * @brief The Codificador class
 * Esta clase se encarga de codificar y decodificar la
 * informacion de la base de datos.
 * @author: Sebastian Insignares
 */
class Codificador
{
public:
    /**
     * @brief Codificador Constructor de la clase
     * @param semillaP - parametro de codificacion.
     */
    Codificador( unsigned long semillaP = 4);

    /**
     * @brief codificar    - Codifica la informacion a guardar en la base de datos.
     *
     * @param textoBinario              - El texto en binario a codificar.
     * @param semilla                   - La semilla de codificacions.
     * @return el texto codificado.
     */
    string codificar(string textoOriginal);

    /**
     * @brief decodificar  - Decodifica la informacion leida de la base de datos.
     *
     * @param textoCodificado           - El texto en binario codificado.
     * @param semilla                   - La semilla de codificacions.
     * @return el texto decodificado.
     */
    string decodificar(string textoCodificado);

private:
    /**
     * @brief semilla - parametro de codificacion.
     */
    unsigned long semilla;

    /**
     * @brief string2bin  - Este Metodo combierte una cadena de caracters, en una representacion
     * de caracteres binarios. ejemplo: el caracter 'A' se combierte en "01000001".
     *
     * @param texto     - Es la cadena de caracteres que se quiere convertir.
     * @return la cadena de caracteres convertida.
     */
    string string2bin(string texto);

    /**
     * @brief bin2String  - Este Metodo combierte una representacion de caracteres binarios
     * en una cadena de caracters. ejemplo: la cadena "01000001" se combierte en el caracter 'A'.
     *
     * @param texto     - string donde se almacena la cadena de caracteres binarios.
     * @return la cadena de caracteres convertida.
     */
    string bin2String(string texto);

    /**
     * @brief correrBloque  - Corre los caracteres del bloque un caracter a la derecha, de tal manera que el ultimo
     * pasa a ser el primero.
     *
     * @param bloque        - bloque al que se le aplica el corrimiento.
     * @return bloque con el corrimiento aplicado.
     */
    string correrBloque(string bloque);

    /**
     * @brief devolverBloque    - Corre los caracteres del bloque un caracter a la izquierda, de tal manera que el primero
     * pasa a ser el ultimo.
     *
     * @param bloque            - bloque al que se le aplica el corrimiento.
     * @return bloque con el corrimiento contrario aplicado.
     */
    string devolverBloque(string bloque);

};

#endif // CODIFICADOR_H
