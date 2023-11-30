// #include "include/types.hpp"
// #include "include/TableSymbol.hpp"
// #include "include/TableReservedWord.hpp"
#include "include/Tercets.hpp"
#include "include/Lexico.hpp"
//#include "include/VectorOfFunction.hpp"
#include "include/AssemblerGenerator.hpp"

#include <iostream>
#include <fstream>
#include <string>
// // // #include <locale.h> // Libreria que contiene la funcion setlocale

using namespace std;

void assembleAndLink(string outputFile);
void loadOnesToTableSymbol( TableSymbol * tableSymbol);
/*
    Este es el main, y en la practica se indico que el sintactico era el main y este es quien pide los tokens al lexico
*/

int main(int arg_count, char *arg_list[]) {
    // checkeo que se haya pasado el archivo a compilar
    if (arg_count < 2) {
        std::cout << "Se requiere al menos el archivo a compilar" << endl;
        exit(0);
    }
    string file_name = arg_list[1];
    
    //  CARGAR ARCHVO A STRING

    // Crea una cadena para almacenar el contenido del archivo, esto es porque acelera la lectura del archivo al ya tenerlo en ram
    std::string contenido;
    std::ifstream archivo(file_name);

    // Verifica que el archivo exista y se pueda abrir
    if (!archivo.is_open()) {
        std::cerr << "El archivo no existe o no se pudo abrir." << std::endl;
        return 1; // Sale del programa con un codigo de error
    }

    string outputFile = "output"; // Valor por defecto

    if (arg_count > 2) {
        outputFile = arg_list[2]; // Si se proporciona un segundo argumento, asignarlo a outputFile
    }else{        
        size_t lastSlashPos = file_name.find_last_of("/\\");
        if (lastSlashPos != std::string::npos) {
            string fileNameAndExtension = file_name.substr(lastSlashPos+1);
            size_t lastDotPos = fileNameAndExtension.find_last_of(".");
            outputFile = fileNameAndExtension.substr(0, lastDotPos);
        } else{
            size_t lastDotPos = file_name.find_last_of(".");
            outputFile = file_name.substr(0, lastDotPos);
        }
    }
    std::cout << "La salida sera: " << outputFile << endl;

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
    extern VectorOfFunction * vectorOfFunctionDeclaredInClasses;

    // cargamos nuestra fase de analisis lexico
    Lexico * lexico = new Lexico(tableSymbol, tableRWords, &contenido, &lineNumber, &isErrorInCode); // la dejamos en la pila porque tiene un tamaño pequeño y su tamaño no es dinámico

    int resultParsing = yyparse(lexico);
    
    if(resultParsing == 0 && !isErrorInCode){
        
        // Solo imprimimos las tablas si no hay errores en el codigo y el parsing resultó exitoso

        std::cout << "\n\n --------------- \n\n";
        tableSymbol->imprimirTabla();
        tableSymbol->imprimirAtributosMetodos();

        std::cout << "\n\n ------bloques de codigo ejecutables--------- \n\n";
        vectorOfFunction->imprimir();
        
        // std::cout << "\n\n ------bloques de códigos declarativos--------- \n\n";
        // vectorOfFunctionDeclaredInClasses->imprimir();
        
        // tableRWords->imprimirTabla();
    
        std::cout << "\n\n --------Lista de tercetos del main------- \n\n";
        tableTercets->print();
    }

    if(resultParsing == 0){
        if(isErrorInCode){
            std::cout << "\n\n --------------- \n\n";
            std::cout << "Parsing exitoso pero errores en codigo" << endl;
            std::cout << "Soluciona los errores para generar el assembler" << endl; 
            std::cout << "\n\n --------------- \n\n";           
        }else{
            std::cout << "\n\n --------------- \n\n";
            std::cout << "Parsing exitoso" << endl;
            std::cout << "Generando el assembler" << endl;
            std::cout << "\n\n --------------- \n\n";
            // generamos el codigo assembler
            AssemblerGenerator * assemblerGenerator = new AssemblerGenerator(outputFile+".asm", tableSymbol, tableTercets, vectorOfFunction);
            loadOnesToTableSymbol(tableSymbol);
            assemblerGenerator->generateAssembler();
        }
    }else{
        yyerror("Se detecto una sentencia invalida");
        std::cout << "\n\n --------------- \n\n";
        std::cout << "Parsing fallo" << endl;
        std::cout << "No se puede generar el assembler" << endl;
        std::cout << "\n\n --------------- \n\n";
    }

    // FOR ONLY READ TOKENS COMMENT THE ABOVE CODE (Line 65 to 78)
    // UNCOMMENT THE NEXT CODE

    // while (!lexico->endOfFile()){
    //     tokenWithLexeme * token = lexico->getToken(); // esto queda guardado en el heap // checkear cuando hay que eliminarlo
        
    //     if(token != nullptr){
    //         std::cout <<  "El token es: " << token->token << " con lexema: " << token->lexeme << endl;
    //         delete token;
    //     };
    // }


    delete tableSymbol;
    delete tableRWords;
    delete tableTercets;
    if(resultParsing == 0 && !isErrorInCode){
        assembleAndLink(outputFile);
    }

    return 0;
}


void assembleAndLink(string outputFile){
    string comandoObj= "C:\\masm32\\bin\\ml /c /Zd /coff " + string("./") + outputFile + ".asm";
    std::cout << endl << endl;
    int resultado = system(comandoObj.c_str());
    std::cout << endl << endl;
    if (resultado == 0){
        std::cout << "OBJ creado exitosamente" << endl << endl << endl;
        string comandoExe = "C:\\masm32\\bin\\Link /SUBSYSTEM:CONSOLE " + string("./") + outputFile + ".obj";
        resultado = system(comandoExe.c_str());
        if (resultado == 0){
            std::cout  << "EXE creado exitosamente" << endl << endl << endl;
        } else {
            std::cout << "Error al intentar realizar el assembler del codigo fuente" << endl;
        }
    } else {
        std::cout << "Error al intentar realizar el link y assembler del codigo fuente" << endl;
    }
}

void loadOnesToTableSymbol( TableSymbol * tableSymbol){
    tableSymbol->insert("1_s", "1_s", "1", "short");
    tableSymbol->insert("1_ui", "1_ui", "1", "unsigned int");
    tableSymbol->insert("1.0", "1.0", "1.0", "float");
};