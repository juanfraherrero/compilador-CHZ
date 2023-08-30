#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "include/Automaton.hpp"
#include "AS1.cpp"
#include "AS2.cpp"
#include "AS3.cpp"
#include "AS4.cpp"


Automaton::Automaton() {
    
    // cargamos la tabla de estados y acciones semanticas
    // debe coincidir el path y además checkear que los límtes de la matriz en el .hpp sean correctos
    this->loadStateTable("src/files/TablaProximoEstado.csv");
    this->loadActionsTable("src/files/TablaAccionesSemanticas.csv");
         
    //esta línea es para ver la matriz cargada
    // this->printMatrix();
}

int Automaton::processCharacter(char character, int actual_state) {

    valueOfMatrix* value = this->getValueOfMatrix(character, actual_state);

    // esto lo debe hacer una accion semantica
    this->tokenToreturn->lexeme+=character;
    // if (value->accionp != NULL){
    //     value->accionp->execute();
    // }   
    
    return value->next_state;
}

valueOfMatrix * Automaton::getValueOfMatrix (char character, int actual_state){
    int column = this->getSubconjunto(character);
    int row = actual_state;
    
    return &this->matrix[row][column];
}

/*
    Acá hay que extender con todos los subconjuntos que se necesiten adecuados a las tablas
*/
int Automaton::getSubconjunto(char character){
    if (isalpha(character)) {
        // std::cout << "Es una letra." << std::endl;
        return 0;
    } else if (isdigit(character)) {
        // std::cout << "Es un número." << std::endl;
        return 0;
    } else if (isspace(character)) {
        // std::cout << "Es un espacio." << std::endl;
        return 1;
    } else {
        // std::cout << "No es una letra, número ni espacio." << std::endl;
        return 0;
    }

}

// devuelve el token con su lexema
tokenWithLexeme* Automaton::getLastToken(){

    tokenWithLexeme *token = new tokenWithLexeme();
    
    // copiamos el token con su lexema
    token->token = this->tokenToreturn->token;
    token->lexeme = this->tokenToreturn->lexeme;
    
    // limpiamos el token usado como buffer para guardar el token a devolver
    this->tokenToreturn->token = 0;
    this->tokenToreturn->lexeme = "";

    return token;
}
// imprime la matriz pasada por parámetro
void Automaton::printMatrix(){
    //imprimimos la matriz de estados
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            cout << this->matrix[i][j].next_state << " ";
        }
        cout << endl;
    } 

    //imprimimos la matriz de acciones
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            AccionSemantica* accion = this->matrix[i][j].accionp;
            if (accion != NULL)
            {
                cout << this->matrix[i][j].accionp->name() << " ";
            }else{
                cout << "NULL ";
            }
        }
        cout << endl;
    }     
}

// checkear si esto no te los crea en cada llamada y nunca desaparecen
AccionSemantica* Automaton::getAccionSemantica(string accionStr){
    // mapa de acciones semanticas
    // Acá se deben agregar
    static std::map<string, AccionSemantica*> actionMap = {
        {"AS1", new AS1()},
        {"AS2", new AS2()},
        {"AS3", new AS3()},
        {"AS4", new AS4()}
        };

    auto it = actionMap.find(accionStr);
    if (it != actionMap.end()) {
        return it->second;
    } else {
        return nullptr;
    }
};

//cargar una tabla desde un .csv pasada por parámetro
void Automaton::loadStateTable(string pathFile){
    
    //Abrir archivo
    ifstream arch(pathFile);
    
    char character;
    string str = "";
    int row = 0;
    int column = 0;
    //recorremos caracter por caracter
    while (arch.get(character)) {
        // si no es ni un salto ni un tab concatenamos
        if(character != '\n' && character != ',') 
        {
            str += character;
        }
        // si es un salto de línea oun tab ontentamos obtener un entero del string y lo guardamos en la matriz
        else 
        {
            try{
                int num = std::stoi(str);
                this->matrix[row][column] = valueOfMatrix{num, NULL};
            }catch(const std::invalid_argument& e){
                this->matrix[row][column] = valueOfMatrix{-1, NULL};
            }

            str = "";
            column++;
            if (column == 28){        
                column = 0;
                row++;
            }
        };
    }
    //esto es para el último elemento de la matriz que siempre falta por propiedades del ifstream
    try{
        int num = std::stoi(str);
        this->matrix[row][column] = valueOfMatrix{num, NULL};
    }catch(const std::invalid_argument& e){
        this->matrix[row][column] = valueOfMatrix{-1, NULL};
    }
};

//cargar una tabla desde un .csv pasada por parámetro
void Automaton::loadActionsTable(string pathFle){

    //Abrir archivo
    ifstream arch(pathFle);
    char character;
    string str = "";
    int row = 0;
    int column = 0;
    // si no es ni un salto ni un tab concatenamos
    while (arch.get(character)) {
        // si no es ni un salto ni un tab concatenamos
        if(character != '\n' && character != ',') // si no es ni un salto ni un tab
        {
            str += character;
        }
        // si es un salto de línea oun tab ontentamos obtener un entero del string y lo guardamos en la matriz
        else 
        {
            AccionSemantica* accion = this->getAccionSemantica(str);
            this->matrix[row][column].accionp = accion;
            
            str = "";
            column++;
            if (column == 28){        
                column = 0;
                row++;
            
            }
        };
    }
    //esto es para el último elemento de la matriz que siempre falta por propiedades del ifstream    
    AccionSemantica* accion = this->getAccionSemantica(str);
    this->matrix[row][column].accionp = accion;
};