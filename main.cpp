#include <iostream>
using namespace std;
#include <fstream>
#include "src/Lexico.cpp"
#include "src/include/types.hpp"
/*
Este es el main, y en la práctica se indico que el sintáctico era el main y este es quien pide los tokens al léxico
*/

int main(int arg_count, char *arg_list[]) {

    if (arg_count < 2) {
        cout << "Se requiere que se pase por parámetro el archivo a compilar" << endl;
        exit(0);
    }

    string file_name = arg_list[1];
    cout << "Compilando archivo: " << file_name << endl;

    Lexico lexico = Lexico(file_name); // la dejamos en la pila porque tiene un tamaño pequeño y su tamaño no es dinámico
    
    tokenWithLexeme *token;

    while (!lexico.endOfFile()) {
        token = lexico.getToken(); // esto queda guardado en el heap // checkear cuando hay que eliminarlo
        cout << token->token << token->lexeme << endl;
        delete token;
    }

    return 0;
}
