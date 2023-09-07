#include "include/Lexico.hpp"
#include "Automaton.cpp"
#include "include/TableSymbol.hpp"
#include "include/TableReservedWord.hpp"
// #include "include/TableSymbol.hpp"
// #include "include/TableReservedWord.hpp"

#include <iostream>
#include <fstream>

Lexico::Lexico(string file_name, TableSymbol* tableSymbol, TableReservedWord* tableRWords) {
    // definimos que archivo va a usar y las variables para hacer el conteo de lineas y caracteres leídos   
    this->file_name = file_name;
    this->line = "";
    this->lineNumber = 0;
    this->character = 0;
    this->eof = false;
    this->automaton = new Automaton(tableSymbol, tableRWords, &(this->lineNumber));
}

tokenWithLexeme *Lexico::getToken(){

    // si el buffer string está vacío, leemos la siguiente línea
    if (this->getLastLine() == "") {
        
        // se encarga de cargarle la siguiente línea al string y checkea si llegó al end of file        
        this->getNextLine();    
    }

    // seteamos el estado del autómata en 0
    int stateAutomaton = 0;

    // obtenemos un token       
    /*
        suponemos que el 19 es el estado final y 20 de errores (ambos terminan el token)
    */
    while (stateAutomaton != 19 && stateAutomaton != 20 ){
        char firstCharacter;
        // si el buffer del autómata está vacío le mandamos otro sino el mismo que tiene
        if(this->automaton->isBufferEmpty()){
            // obtenemos el primer caracter de la línea
            firstCharacter = this->line[0]; 
            // eliminamos ese caracter de la línea
            this->line.erase(0, 1); 
        }
        else{
            firstCharacter = this->automaton->getAndClearBuffer(); 
        }
        

        // procesamos el caracter por el autómata esperando el estado siguiente
        stateAutomaton = this->automaton->processCharacter(firstCharacter, stateAutomaton);
    }

    return this->automaton->getCopyOfTokenAndResetToken();
}

// checkea si es el final de archivo
bool Lexico::endOfFile(){
    return this->eof;
}

string Lexico::getLastLine(){
    return this->line;
}

// obtiene la siguiente línea del archivo y la guarda en el buffer string
void Lexico::getNextLine(){
    
    //abrimos el archivo y nos posicionamos en el caracter que quedó pendiente de leer
    file.open(this->file_name);
    file.seekg(this->character); // nos posicionamos en el caracter que quedó pendiente de leer
    
    // leemos la línea y seteamos si es o no el fin del archivo
    this->eof = !(bool)getline(file, this->line);
    
    // incrementamos el contador de líneas
    this->incrementLineNumber(); 

    // guardamos la posición del último caracter leído
    this->character = file.tellg(); 
    
    // cerramos el archivo
    file.close();
    return;
}

void Lexico::incrementLineNumber(){
    this->lineNumber++;
}