#include "include/types.hpp"
#include "include/TableSymbol.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
TableSymbol::TableSymbol(){
    this->scope = ":main";
};
TableSymbol::TableSymbol(string _scope){
    this->scope = _scope;
};

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
// insertar un elemento en la tabla
string TableSymbol::insertIdentifierTruncated(const string& key, const string& lexema, const string& value, const string& type, string _fullIdentifier) {
    // buscamos si ya existe ese fullIdentifier en la tabla
    // si existe sumamos uno al contador
    // sino existe lo creamos y lo agregamos a la tabla
    
    bool finded = false;
    // recorremos uno por uno los simbolos de la tabla
    for (const auto& par : symbolTable) {
        symbol* simbolo = par.second; // Obtenemos el el puntero al simbolo

        // Verificamos el atributo 'fullIdentifier' coincide con el pasado por parámetro
        if (simbolo->fullIdentifier == _fullIdentifier) {
            // encontró un símbolo con esa clave
            // incrementamos el contador de ese símbolo
            simbolo->count++;
            finded = true;
            break;
        }
    }

    if(!finded){
        //no encontró un símbolo con esa clave
        // Crear un nuevo simbolo y almacenarlo en la tabla
        string lexemeTruncated = "var$"+to_string(this->cantVartruncated);
        symbol* newSymbol = new symbol(lexemeTruncated, lexemeTruncated, type, "", _fullIdentifier);
        symbolTable[lexemeTruncated] = newSymbol;
        this->cantVartruncated++;
        return lexemeTruncated;
    }
    return "";
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
        cout << "Clave: " << pair.first << "\t Lexema: " << symbol->lexema << "\t Valor: " << symbol->value << "\t Tipo: " << symbol->type << "\t Uso: " << symbol->uso << "\t fullIdentifier: " << symbol->fullIdentifier <<endl;
    }
}


void TableSymbol::imprimirAtributosMetodos() {
    cout << "\n\nAtributos y métodos de clase:\n\n" << endl;
    for (const auto& pair : symbolTable) {
        const symbol* sm = pair.second;
        if (sm->uso == "clase"){
            cout << "Clave: " << pair.first << "\t Lexema: " << sm->lexema << "\t Valor: " << sm->value << "\t Tipo: " << sm->type << "\t Uso: " << sm->uso << "\t fullIdentifier: " << sm->fullIdentifier <<endl;
            
            sm->attributesAndMethodsVector->imprimirTabla();
        }
            
    }
}
unordered_map<string, symbol*> TableSymbol::getSymbolTable(){
    return this->symbolTable;
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
        if(it->second->cantParam == 0){
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
        it->second->cantParam = stoul(cant);
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
int TableSymbol::getDiffOffScope(const string varWithScope,const string& uso, const string& scope) {
    //  que uno le pasa por la variable "ambito" el ámbito al que queremos calcular la diferencia de niveles.
    // varWithScope:  cs:main:func3     scope : main
    // scopeAux: cs:main
    
    size_t firstColonPos = varWithScope.find(':');
    string nameVar = varWithScope.substr(0, firstColonPos);
    string scopeAux = nameVar + scope;
    int diff = 0;
    size_t lastColonPosAmbito = scopeAux.find_last_of(':'); // Buscamos la última aparición de ':' en el ámbito

    //comparamos el ambito actual con el scope
    while (lastColonPosAmbito != string::npos) {
        if (varWithScope != scopeAux){
            diff++;
        }
        else{ 
            if (CompareUse(scopeAux,uso))
            {   
                return diff;
            }
        }
        scopeAux = scopeAux.substr(0, lastColonPosAmbito);
        lastColonPosAmbito = scopeAux.find_last_of(':');
    }
    return -1;
}

bool TableSymbol::CompareUse(const string scope, const string uso){
    auto it = symbolTable.find(scope);
    if (it != symbolTable.end()) {
        if(it->second->uso == uso){
            return true;
        }
    }
    return false;
}

symbol* TableSymbol:: getFirstSymbolMatching(const string& varWithScope,const string& uso, const string& scope)
{
    // b:main:func3
    // main:func3
    int diffScope = getDiffOffScope(varWithScope, uso, scope);
    if(diffScope == -1){ // sino encontramos coincidencia retornamos nullptr
        return nullptr;
    }
    size_t firstColonPos = varWithScope.find(':');
    string nameVar = varWithScope.substr(0, firstColonPos);
    string ambitoAux = nameVar+scope;
    while (diffScope != 0){
        size_t lastColonPos = ambitoAux.find_last_of(':');
        ambitoAux = ambitoAux.substr(0, lastColonPos);
        diffScope--;
    };
    auto it = symbolTable.find(ambitoAux);
    if (it != symbolTable.end()) {
        return it->second; // Devolver el puntero al símbolo si se encuentra
    }
    return nullptr;
}

symbol* TableSymbol:: getFirstSymbolMatching2(const string var,const string uso, string scope)
{
    // la idea es que recibe una variable y el scope actual
    // debe de buscar en la tabla de símbolos si conicide con el uso y el scope
    // devuelve nullptr si no encuentra coincidencia y sino devuelve la coincidencia


    //creamos un scopeaux para poder modificar ya que es una constante
    while (scope != ""){
        // recorrer cada uno de los simbolos de la tabla, si lo encuentra retorna el simbolo
        for (const auto& par : this->symbolTable){
            symbol* simbolo = par.second;
            // verificamos que el valor de lexema sea el mismo que el de la variable con el scope,ademas tambien verifcamos el uso
            if(var+scope == simbolo->lexema &&  simbolo->uso == uso){    
                // encontramos el primero símbolo con mayor longitud de scope que coincide nombre y uso
                return simbolo;
            }
        }
        
        // recortamos el scope
        size_t lastColonPos = scope.find_last_of(':');
        scope = scope.substr(0, lastColonPos);  
        //pregutamos si esta vacio el scopeAux si es asi devolvemos nullptr
        if (scope == ""){
            return nullptr;
        }
    }
}


int TableSymbol:: getDiffOffScope2(const string var,const string uso, string scope)
{
    // la idea es que recibe una variable y el scope actual
    // debe de buscar en la tabla de símbolos si conicide con el uso y el scope
    // a medida que recorta un scope summa 1 al diff para saber la distancia a la que se encuentra
    // si encuentra retorna ese da ino devuelve -1

    int diff = 0;
    while (scope != ""){
        // recorrer cada uno de los simbolos de la tabla, si lo encuentra retorna el simbolo
        for (const auto& par : this->symbolTable){
            symbol* simbolo = par.second;

            // verificamos que el valor de lexema sea el mismo que el de la variable con el scope, ademas tambien verifcamos el uso
            if(var+scope == simbolo->lexema &&  simbolo->uso == uso){
                // encontramos el primero símbolo con mayor longitud de scope que coincide nombre y uso
                return diff;
            }
        }
        diff++;
        // recortamos el scope
        size_t lastColonPos = scope.find_last_of(':');
        scope = scope.substr(0, lastColonPos);  
        //pregutamos si esta vacio el scope si es asi devolvemos nullptr
        if (scope == ""){
            return -1;
        }
    }
    return -1;
}

bool TableSymbol::existMethodInTable(const string key, const string uso){
    
    // recorremos la tabla por cada símbolo
    for (const auto& pair : symbolTable) {
        const symbol* sm = pair.second;

        // buscamos el símbolo que coincida con el nombre y el uso
        string lexemaAux = sm->lexema.substr(0, sm->lexema.find(":"));
        if (lexemaAux == key && sm->uso == uso){
            return true;
        }
    }
    return false;
}
         
// Destructor para liberar la memoria de los símbolos
TableSymbol::~TableSymbol() {
    for (auto& pair : symbolTable) {
        delete pair.second;
    }
}

