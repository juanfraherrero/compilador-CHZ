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
    
    // Checheamos si el string que guarda lo ultimo leído está vacío
        // si está vacío leemos la siguiente línea (se debe verificar cuando se llega al end of file)
        // si no está vacío, no hacemos nada
    // Seteamos el estado del automata en estado inicial "0"
    // ciclamos leyendo caracter del string y procesandolo por el autómata
        // ciclamos hasta que el estado recibido sea el final
        // el autómata internamente se encarga de ejecutar las aciones semánticas correspondientes (también debe de definir el token correspondiente)
    // al llegar al estado final, devolvemos el token correspondiente y el lexema si es necesario

    // obtenemos la línea siguiente si la última línea leída está vacía
    if (this->getLastLine() == "") {
        cout << "La línea está vacía" << endl;
        this->getNextLine();    // se encarga de cargarle la siguiente línea al string y checkea si llegó al end of file
        cout << "Ahora la línea es: " << this->getLastLine() << endl;
    }

    int stateAutomaton = 0;

    // obtenemos un token // suponemos que el 30 es el estado final
    while (stateAutomaton != 30){
        
        char firstCharacter = this->line[0]; // obtenemos el primer caracter de la línea
        cout << "Linea PREV: " << this->line << endl;
        this->line.erase(0, 1); // y se lo eliminamos a la línea
        cout << "Linea AFTER: " << this->line << endl;
        stateAutomaton = this->automaton->processCharacter(firstCharacter, stateAutomaton);
        if(this->line == ""){
            stateAutomaton = 30;
        }
    }

    cout << "El estado final es: " << stateAutomaton << endl;
    return this->automaton->getLastToken();
}

bool Lexico::endOfFile(){
    return this->eof;
}

string Lexico::getLastLine(){
    return this->line;
}

void Lexico::getNextLine(){
    cout << " Obteniendo la siguiente línea" << endl;
    //abriomos el archivo
    file.open(this->file_name);
    file.seekg(this->character); // nos posicionamos en el caracter que quedó pendiente de leer
    
    this->eof = !(bool)getline(file, this->line); // cargamos la línea y seteamos si es o no el fin del archivo
    
    this->incrementLineNumber(); // incrementamos el contador de líneas

    this->character = file.tellg(); // guardamos la posición del último caracter leído
    
    // cerramos el archivo
    file.close();
    return;
}

void Lexico::incrementLineNumber(){
    this->lineNumber++;
}