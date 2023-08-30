#include <iostream>
using namespace std;
#include <fstream>
#include "src/Lexico.cpp"
#include "src/include/types.hpp"
/*
Este es el main, y en la práctica se indico que el sintáctico era el main y este es quien pide los tokens al léxico
*/

int main(int arg_count, char *arg_list[]) {

    // checkeo que se haya pasado el archivo a compilar
    if (arg_count < 2) {
        cout << "Se requiere que se pase por parámetro el archivo a compilar" << endl;
        exit(0);
    }

    string file_name = arg_list[1];
    cout << "Compilando archivo: " << file_name << endl;

    // cargamos nuestra fase de analisis léxico
    Lexico lexico = Lexico(file_name); // la dejamos en la pila porque tiene un tamaño pequeño y su tamaño no es dinámico
    
    tokenWithLexeme *token;
    //esto se supone que será reemplazado por el ya que irá pidiendo tokens
    while (!lexico.endOfFile()) {
        token = lexico.getToken(); // esto queda guardado en el heap // checkear cuando hay que eliminarlo
        cout << "TOKEN ---->>>> " << token->lexeme << endl;
        
        // le das uso al token y antes de terminar el while lo borras porque el get Token te da otro
        delete token;
    }

    return 0;
}
