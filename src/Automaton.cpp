#include "include/Automaton.hpp"
#include "Acciones/AS1.cpp"
#include "Acciones/AS2.cpp"
#include "Acciones/AS3.cpp"
#include "Acciones/AS4.cpp"
#include "Acciones/AS5.cpp"
#include "Acciones/AS6.cpp"
#include "Acciones/AS7.cpp"

#include "Acciones/AS9.cpp"

#include "Acciones/AS14.cpp"
#include "Acciones/ASE.cpp"
#include "TableSymbol.cpp"
#include "TableReservedWord.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

Automaton::Automaton(TableSymbol* tableSymbol, TableReservedWord* tableRWords, int* ptrLineNumber) {
    
    // cargamos la tabla de estados y acciones semanticas
    // debe coincidir el path y además checkear que los límtes de la matriz en el .hpp sean correctos
    this->loadStateTable("src/files/TablaProximoEstado.csv");
    this->loadActionsTable("src/files/TablaAccionesSemanticas.csv");

    // guardamos las tablas
    this->tableSymbol = tableSymbol;
    this->tableRWords = tableRWords;
    this->ptrLineNumber = ptrLineNumber;
    //esta línea es para ver la matriz cargada
    // this->printMatrix();
}

int Automaton::processCharacter(char character, int actual_state) {

    valueOfMatrix* value = this->getValueOfMatrix(character, actual_state);

    string prb = "NULL";

    // // esto lo debe hacer una accion semantica
    // this->tokenToreturn->lexeme+=character;
    if (value->accionp != NULL){
        value->accionp->execute(this, character, this->tableSymbol, this->tableRWords);
        prb = value->accionp->name();
    }   
    
    
    // for (int i = 0; i < sizeof(char); ++i) {
    //     std::cout << static_cast<int>(reinterpret_cast<unsigned char*>(&character)[i]) << " ";
    // }
    // std::cout << std::endl;
    cout << "character: " << character << " state: " << actual_state << " next state: " << value->next_state << "x" << endl;
    cout << "la acción a ejecutar es: " << prb << endl;
    

    return value->next_state;
}

valueOfMatrix * Automaton::getValueOfMatrix (char character, int actual_state){
    int column = this->getSubconjunto(character);
    int row = actual_state;
    
    return &this->matrix[row][column];
}

// Obtenemos la columna dado el caracter obtenido
int Automaton::getSubconjunto(char character){
    switch (character)
    {
        case '\n':
            return 0;
            break;
        case 's':
            return 1;
            break;
        case 'u':
            return 2;
            break;
        case 'i':
            return 3;
            break;
        case ' ':         
            return 4;
            break;
        case '.':
            return 5;
            break;
        case 'e':
            return 6;
            break;
        case 'E':      
            return 7;
            break;
        case '+':
            return 8;
            break;
        case '-':
            return 9;
            break;
        case '/':
            return 10;
            break;
        case '*':
            return 11;
            break;
        case '=':
            return 12;
            break;
        case '!':
            return 13;
            break;
        case '<':
            return 14;
            break;
        case '>':
            return 15;
            break;
        case '{':
            return 16;
            break;
        case '}':
            return 17;
            break;
        case '(':
            return 18;
            break;
        case ',':
            return 19;
            break;
        case ';':
            return 20;
            break;
        case '#':
            return 21;
            break;
        case ')':
            return 22;
            break;
        case '_':
            return 26;
            break;
        
        // sino es ninguno de los anteriores caracteresverificamos si es parte de un subconjunto
        default:
            if(islower(character)) // 'l'
                return 23;
            else if(isupper(character)) // 'L'
                return 24;
            else if(isdigit(character)) // 'd'
                return 25;
            else                        // NV
                return 27;
            break;
    }
}

// devuelve el token con su lexema
tokenWithLexeme* Automaton::getToken(){
    return this->tokenToreturn;
}

// devuelve una copia del token con su lexema
tokenWithLexeme* Automaton::getCopyOfToken(){

    tokenWithLexeme *token = new tokenWithLexeme();
    
    // copiamos el token con su lexema
    token->token = this->tokenToreturn->token;
    token->lexeme = this->tokenToreturn->lexeme;
    
    // // limpiamos el token usado como buffer para guardar el token a devolver
    // this->tokenToreturn->token = 0;
    // this->tokenToreturn->lexeme = "";

    return token;
}
// devuelve el token con su lexema y resetea el token del autómata
tokenWithLexeme* Automaton::getCopyOfTokenAndResetToken(){

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
        {"AS4", new AS4()},
        {"AS5", new AS5()},
        {"AS6", new AS6()},
        {"AS7", new AS7()},
        
        {"AS9", new AS9()},

        {"AS14", new AS14()},
        {"ASE", new ASE()},
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

bool Automaton::isBufferEmpty(){
    return this->bufferForCharacter == '\0';
};

void Automaton::setBuffer(char character){
    this->bufferForCharacter = character;
};

char Automaton::getAndClearBuffer(){
    char character = this->bufferForCharacter;
    this->bufferForCharacter = '\0';
    return character;
};

int * Automaton::getPtrLineNumber(){
    return this->ptrLineNumber;
};
