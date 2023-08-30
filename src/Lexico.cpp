#include <iostream>
#include <fstream>
#include "include/Lexico.hpp"
#include "Automaton.cpp"

Lexico::Lexico(string file_name) {
    // definimos que archivo va a usar y las variables para hacer el conteo de lineas y caracteres leídos   
    this->file_name = file_name;
    this->line = "";
    this->lineNumber = 0;
    this->character = 0;
    this->eof = false;
    this->automaton = new Automaton();
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
        Esto está fijado para que vaya devolviendo las plabras, hayque juntarlo con el automata
        
        suponemos que el 30 es el estado final
    */
    while (stateAutomaton != 30){
        
        // obtenemos el primer caracter de la línea
        char firstCharacter = this->line[0]; 
        
        // eliminamos ese caracter de la línea
        this->line.erase(0, 1); 

        // procesamos el caracter por el autómata esperando el estado siguiente
        stateAutomaton = this->automaton->processCharacter(firstCharacter, stateAutomaton);
        
        /*
            ACA LO ESTAMOS FORZANDO A QUE TERMINE CUANDO SE ACABA LA LÍNEA
        */
        if(this->line == ""){
            stateAutomaton = 30;
        }
    }

    return this->automaton->getLastToken();
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