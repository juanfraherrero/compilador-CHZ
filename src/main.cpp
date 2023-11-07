// #include "include/types.hpp"
// #include "include/TableSymbol.hpp"
// #include "include/TableReservedWord.hpp"
#include "include/Tercets.hpp"
#include "include/Lexico.hpp"
#include "include/VectorOfFunction.hpp"
#include "include/AssemblerGenerator.hpp"

#include <iostream>
#include <fstream>
#include <string>
// // // #include <locale.h> // Libreria que contiene la funcion setlocale

using namespace std;



/*
    Este es el main, y en la practica se indico que el sintactico era el main y este es quien pide los tokens al lexico
*/

int main(int arg_count, char *arg_list[]) {
    
    // // // setlocale(LC_CTYPE, "Spanish");   
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

    // Verifica que el archivo exista y se pueda abrir
    if (!archivo.is_open()) {
        std::cerr << "El archivo no existe o no se pudo abrir." << std::endl;
        return 1; // Sale del programa con un codigo de error
    }

    // Lee el contenido del archivo linea por linea y lo agrega a la cadena
    std::string linea;
    while (std::getline(archivo, linea)) {
        contenido += linea + '\n'; // Añade una nueva linea despues de cada linea leida
    }
    // Cierra el archivo
    archivo.close();

    // INICIAR EL LEXICO 

    extern int yyparse(Lexico* lexico);
    
    extern int lineNumber;
    extern bool isErrorInCode;
    extern void yyerror(string s);

    extern TableSymbol* tableSymbol;
    extern TableReservedWord* tableRWords;
    extern Tercets* tableTercets;
    extern VectorOfFunction * vectorOfFunction;

    // cargamos nuestra fase de analisis lexico
    Lexico * lexico = new Lexico(tableSymbol, tableRWords, &contenido, &lineNumber); // la dejamos en la pila porque tiene un tamaño pequeño y su tamaño no es dinámico

    int resultParsing = yyparse(lexico);
    
    if(resultParsing == 0){
        if(isErrorInCode){
            cout << "\n\n --------------- \n\n";
            cout << "Parsing exitoso pero errores en codigo" << endl;
            cout << "Soluciona los errores para generar el assembler" << endl;            
        }else{
            cout << "\n\n --------------- \n\n";
            cout << "Parsing exitoso" << endl;
            cout << "Generando el assembler" << endl;
            // generamos el codigo assembler
            // AssemblerGenerator * assemblerGenerator = new AssemblerGenerator("output.asm");
            // assemblerGenerator->generateAssembler(tableTercets);
        }
    }else{
        yyerror("Se detecto una sentencia invalida");
        cout << "\n\n --------------- \n\n";
        cout << "Parsing fallo" << endl;
        cout << "No se puede generar el assembler" << endl;
    }

    // FOR ONLY READ TOKENS COMMENT THE ABOVE CODE (Line 65 to 78)
    // UNCOMMENT THE NEXT CODE

    // while (!lexico->endOfFile()){
    //     tokenWithLexeme * token = lexico->getToken(); // esto queda guardado en el heap // checkear cuando hay que eliminarlo
        
    //     if(token != nullptr){
    //         cout <<  "El token es: " << token->token << " con lexema: " << token->lexeme << endl;
    //         delete token;
    //     };
    // }
        

    cout << "\n\n --------------- \n\n";
    tableSymbol->imprimirTabla();
    tableSymbol->imprimirAtributosMetodos();
    vectorOfFunction->imprimir();
    // tableRWords->imprimirTabla();
    cout << "\n\n --------Lista de tercetos del main------- \n\n";
    tableTercets->print();


    delete tableSymbol;
    delete tableRWords;
    delete tableTercets;
    return 0;
}
