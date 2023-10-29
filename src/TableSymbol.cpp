#include "include/types.hpp"
#include "include/TableSymbol.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// devuelve un puntero al simbolo buscado
symbol* TableSymbol::getSymbol(const string& key) {

    auto it = symbolTable.find(key);
    if (it != symbolTable.end()) {
        return it->second; // Devolver el puntero al símbolo si se encuentra
    }
    return nullptr; // Devolver nullptr si la clave no se encuentra
}

// insertar un elemento en la tabla
void TableSymbol::insert(const string& key, const string& lexema, const string& value, const string& type) {
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()) {
        // encontró un símbolo con esa clave
        // incrementamos el contador de ese símbolo
        it->second->count++;
    }else{
        //no encontró un símbolo con esa clave
        // Crear un nuevo simbolo y almacenarlo en la tabla
        symbol* newSymbol = new symbol(lexema, value, type);
        symbolTable[key] = newSymbol;
    }
    

}
// insertar un simbolo en la tabla, inserta el puntero (NO HACE UNA COPIA DEL SIMBOLO)
void TableSymbol::insert(symbol * symbol) {
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(symbol->lexema);
    if (it != symbolTable.end()) {
        // encontró un símbolo con esa clave
        // incrementamos el contador de ese símbolo
        it->second->count++;
    }else{
        //no encontró un símbolo con esa clave
        symbolTable[symbol->lexema] = symbol;
    }
    

}

// Función para imprimir la tabla completa
void TableSymbol::imprimirTabla() {
    cout << "\n\nTabla de símbolos:\n\n" << endl;
    for (const auto& pair : symbolTable) {
        const symbol* symbol = pair.second;
        cout << "Clave: " << pair.first << "\t Lexema: " << symbol->lexema << "\t Valor: " << symbol->value << "\t Tipo: " << symbol->type << "\t Uso: " << symbol->uso << endl;
    }
}

void TableSymbol::deleteSymbol(const string& key){
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()) {
        //no encontró un símbolo con esa clave
        // decrementamos el contador de ese símbolo   
        it->second->count--;
        if(it->second->count <= 0){
            // si el contador es 0 o menor, eliminamos el símbolo de la tabla
            delete it->second;
            symbolTable.erase(it);
        }
    }
}

void TableSymbol::setUso(const string& uso, const string& key){
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()){
        it->second->uso = uso;
    }
}

string TableSymbol::getUso(const string& key){
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()){
        return it->second->uso;
    }else{
        return "";
    }
}

int TableSymbol::getCantParam(const string& key){
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()){
        if(it->second->cantParam == "0"){
            return 0;
        }else{
            return 1;
        }
    }else{
        return -1;
    }
}

void TableSymbol::setCantParam(const string& key, const string& cant){
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()){
        it->second->cantParam = cant;
    }
}

void TableSymbol::setTypeParam(const string& key, const string& type){
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()){
        it->second->typeParam = type;
    }
}

string TableSymbol::returnTypeParam(const string& key){
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()){
        return it->second->typeParam;
    }else{
        return "";
    }
}

void TableSymbol::addScope(const string& ambito){
    //suponemos uno le pasa por la variable "key" el ambito actual y se busca
    //añadir al scope, para ello se entiende que es concatenar el ambito actual
    //junto con el valor actual de la variable scope
    scope = scope + ":"+ ambito;
}

void TableSymbol::deleteScope(){
    // se busca eliminar el ultimo ambito de la variable scope
    //scope = scope - ultimo valor;
    size_t lastColonPos = scope.find_last_of(':');
    scope = scope.substr(0, lastColonPos);
}

string TableSymbol::getScope(){
    return scope;
}
// x:main:b:c   symbolWithScope
// x            nameVar
// :maih:b:c    scope

// nameVar+scope
// symbolWithScope
int TableSymbol::getDiffOffScope(const string& ambito,const string& uso) {
    // Suponemos que uno le pasa por la variable "ambito" el ámbito al que queremos calcular la diferencia de niveles.
    size_t firstColonPos = ambito.find(':');
    string nameVar = ambito.substr(0, firstColonPos);
    string scopeAux = nameVar + scope;
    int diff = 0;
    string ambitoActual = ambito;  // Creamos una copia de ambito para no modificar el original
    size_t lastColonPosAmbito = ambitoActual.find_last_of(':'); // Buscamos la última aparición de ':' en el ámbito

    //comparamos el ambito actual con el scope
    while (lastColonPosAmbito != string::npos) {
        if (ambitoActual != scopeAux){
            diff++;
        }
        else{ 
            if (CompareUse(ambitoActual,uso))
            {   
                return diff;
            }
        }
        ambitoActual = ambitoActual.substr(0, lastColonPosAmbito);
        lastColonPosAmbito = ambitoActual.find_last_of(':');
    }
    return -1;
}

bool TableSymbol::CompareUse(const string& ambito, const string& uso){
    auto it = symbolTable.find(ambito);
    if (it != symbolTable.end()) {
        if(it->second->uso == uso){
            return true;
        }
    }
    return false;
}

symbol* TableSymbol:: getFirstSymbolMatching(const string& ambito,const string& uso)
{
    int diffScope = getDiffOffScope(ambito,uso);
    
    if(diffScope == -1){ // sino encontramos coincidencia retornamos nullptr
        return nullptr;
    }
    string ambitoAux = ambito + scope;
    for (size_t i = 0; i <= diffScope; ++i) {
        size_t lastColonPos = ambitoAux.find_last_of(':');
        ambitoAux= ambitoAux.substr(0, lastColonPos);
       }
    auto it = symbolTable.find(ambitoAux);
    if (it != symbolTable.end()) {
        return it->second; // Devolver el puntero al símbolo si se encuentra
    }
    return nullptr;
}
// Destructor para liberar la memoria de los símbolos
TableSymbol::~TableSymbol() {
    for (auto& pair : symbolTable) {
        delete pair.second;
    }
}

