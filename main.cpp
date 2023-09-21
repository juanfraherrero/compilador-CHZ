#include "src/include/types.hpp"
#include "src/include/TableSymbol.hpp"
#include "src/include/TableReservedWord.hpp"
#include "src/Lexico.cpp"
#include "src/Parser.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



/*
    Este es el main, y en la práctica se indico que el sintáctico era el main y este es quien pide los tokens al léxico
*/

int main(int arg_count, char *arg_list[]) {
    
    // checkeo que se haya pasado el archivo a compilar
    if (arg_count < 2) {
        cout << "Se requiere el archivo a compilar" << endl;
        exit(0);
    }

    string file_name = arg_list[1];
    cout << "Compilando archivo: " << file_name << endl;
    
    //  CARGAR ARCHVO A STRING

    // Crea una cadena para almacenar el contenido del archivo, esto es porque acelera la lectura del archivo al ya tenerlo en ram
    std::string contenido;
    std::ifstream archivo(file_name);
    // Lee el contenido del archivo línea por línea y lo agrega a la cadena
    std::string linea;
    while (std::getline(archivo, linea)) {
        contenido += linea + '\n'; // Añade una nueva línea después de cada línea leída
    }
    // Cierra el archivo
    archivo.close();

    // INICIAR EL LEXICO 

    int lineNumber = 1;

    // generamos la tabla de símbolos
    TableSymbol* tableSymbol = new TableSymbol();

    // generamos la tabla de palabras reservadas
    TableReservedWord* tableRWords = new TableReservedWord();

    // cargamos nuestra fase de analisis léxico
    Lexico * lexico = new Lexico(tableSymbol, tableRWords, &contenido, &lineNumber); // la dejamos en la pila porque tiene un tamaño pequeño y su tamaño no es dinámico

    
    cout << "\n\n EJECUCIÓN \n\n";

    int resultParsing = yyparse(lexico, &lineNumber);
    if(resultParsing == 0){
        cout << "\n\n --------------- \n\n";
        cout << "Parsing succed" << endl;
    }else{
        cout << "\n\n --------------- \n\n";
        cout << "Parsing failed" << endl;
    }

    cout << "\n\n --------------- \n\n";

    tableSymbol->imprimirTabla();
    tableRWords->imprimirTabla();


    delete tableSymbol;
    delete tableRWords;

    return 0;
}
