#include "include/Tercet.hpp"

#include <iostream>
#include <string>
#include "include/types.hpp"
using namespace std;

Tercet::Tercet(string op, string arg1, string arg2){
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
}

string Tercet::getOp() const{
    return this->op;
}

string Tercet::getArg1() const{
    return this->arg1;
}

string Tercet::getArg2() const{
    return this->arg2;
}  

void Tercet::setArg1(string arg1){
    this->arg1 = arg1;
}   

void Tercet::setArg2(string arg2){
    this->arg2 = arg2;
}

void Tercet::print(){
    cout << "(" + this->op + "," + this->arg1 + "," + this->arg2  + ")" << endl;
}

bool Tercet::opIsTercet(int op){
    if (op == 1)
        return this->arg1[0] == '%';
    else if (op == 2)
        return this->arg2[0] == '%';
}

string Tercet::getAssembler(TableSymbol * tableSymbols){
    string out = "";
    string op1 = "";
    string op2 = "";
    string typeOfFirstArg;
    
    //Primero verificamos que los operandos sean referencias a tercetos. En caso de serlo, los reemplazamos por la variable auxiliar que guarda el resultado del terceto.
    if (this->opIsTercet(1)){
        op1 = "@aux" + this->arg1.substr(1);
        symbol * firstArg = tableSymbols->getSymbol(op1);
        if (firstArg)
            typeOfFirstArg = firstArg->type;
    }
    else{
        if (this->op == "print"){ //Si se trata de un print, se reemplazan todos los espacios por guiones bajos.
            op1 = reemplazarEspacios(this->arg1);
        } else {
            op1 = "_" + this->arg1;
            symbol * firstArg = tableSymbols->getSymbol(this->arg1);
            if (firstArg)
                typeOfFirstArg = firstArg->type;          
        }
    }

    if (this->opIsTercet(2)){
        op2 = "@aux" + this->arg2.substr(1);
    }
    else{
        op2 = "_" + this->arg2;
    }

    //Suma, chequeando overflow en suma de enteros
    if (this->op == "+"){
        this->auxVariable = tableSymbols->getAuxVariable();

        symbol * auxSymbol = new symbol(this->auxVariable, "", typeOfFirstArg, "auxVariable");
        tableSymbols->insert(auxSymbol);
        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "ADD AX, " + op2 + "\n";
            out += "MOV " + this->auxVariable + ", AX\n";
            out += "JO errorSumaEnteros\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FADD " + op2 + "\n";
            out += "FSTP " + this->auxVariable + "\n";
        }
        
    }
    //Resta
    else if (this->op == "-"){
        this->auxVariable = tableSymbols->getAuxVariable();

        symbol * auxSymbol = new symbol(this->auxVariable, "", typeOfFirstArg, "auxVariable");
        tableSymbols->insert(auxSymbol);

        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "SUB AX, " + op2 + "\n";
            out += "MOV " + this->auxVariable + ", AX\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FSUB " + op2 + "\n";
            out += "FSTP " + this->auxVariable + "\n";
        }
    }
    //Multiplicacion
    else if (this->op == "*"){
        this->auxVariable = tableSymbols->getAuxVariable();

        symbol * auxSymbol = new symbol(this->auxVariable, "", typeOfFirstArg, "auxVariable");
        tableSymbols->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AL, " + op1 + "\n";
            out += "IMUL AL" + op2 + "\n";
            out += "MOV " + this->auxVariable + ", AL\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "MUL AX" + op2 + "\n";
            out += "MOV " + this->auxVariable + ", AX\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FMUL " + op2 + "\n";
            out += "FSTP " + this->auxVariable + "\n";
            out += "JO errorProductoFlotantes\n";
        }
    }
    //Division
    else if (this->op == "/"){
        this->auxVariable = tableSymbols->getAuxVariable();

        symbol * auxSymbol = new symbol(this->auxVariable, "", typeOfFirstArg, "auxVariable");
        tableSymbols->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AX, " + op1 + "\n";
            out += "IDIV " + op2 + "\n";
            out += "MOV " + this->auxVariable + ", AL\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "DIV " + op2 + "\n";
            out += "MOV " + this->auxVariable + ", AX\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FDIV " + op2 + "\n";
            out += "FSTP " + this->auxVariable + "\n";
        }
    }
    //Asignacion
    else if (this->op == "="){
        if (typeOfFirstArg == "short"){
            out += "MOV AX, " + op2 + "\n";
            out += "MOV " + op1 + ", AX\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AL, " + op2 + "\n";
            out += "MOV " + op1 + ", AL\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op2 + "\n";
            out += "FSTP " + op1 + "\n";
        }
    }
    //Comparacion igual
    else if (this->op == "=="){
        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JNE ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JNE ";
        }
    }
    //Comparacion menor o igual
    else if (this->op == "<="){
        if (typeOfFirstArg == "short"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JG ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JA ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JG ";
        }
    }
    //Comparacion menor
    else if (this->op == "<"){
        if (typeOfFirstArg == "short"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JGE ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JAE ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JGE ";
        }
    }
    //Comparacion mayor o igual
    else if (this->op == ">="){
        if (typeOfFirstArg == "short"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JL";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JB ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JL ";
        }
    }
    //Comparacion mayor
    else if (this->op == ">"){
        if (typeOfFirstArg == "short"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JLE ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JBE ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JLE ";
        }
    }
    //Comparacion distinto
    else if (this->op == "!!"){
        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JE ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JE ";
        }
    }
    //Branch por falso
    else if (this->op == "BF"){
        out+= "Label" + this->arg2.substr(1) + "\n";
    }
    //Branch incondicional
    else if (this->op == "BI"){
        out+= "JMP Label" + this->arg2.substr(1) + "\n";
    }
    //Label
    else if (this->op.substr(0,5) == "Label"){
        out+= this->op + ":";
    }
    //Llamado a subrutina
    else if (this->op == "call"){
        out += "CALL " + op1 + "\n";
    }
    //Return
    else if (this->op == "return"){
        out += "RET" "\n";
    }
    //Print
    else if (this->op == "print"){
        out += "INVOKE MessageBox, NULL, addr " + op1 + ", addr " + op1 + ", MB_OK" + "\n";
    }
    //Parametro real
    else if (this->op == "paramReal"){
        if (this->arg2 == "short"){
            out += "MOV AX, " + op1 + "\n";
        }
        else if (this->arg2 == "unsigned int"){
            out += "MOV AL, " + op1 + "\n";
        }
        else if (this->arg2 == "float"){
            out += "FLD " + op1 + "\n";
        }
    }
    //Parametro formal
    else if (this->op == "paramFormal"){
        if (this->arg2 == "short"){
            out += "MOV " + op1 + ", AX\n";
        }
        else if (this->arg2 == "unsigned int"){
            out += "MOV " + op1 + ", AL\n";
        }
        else if (this->arg2 == "float"){
            out += "FSTP " + op1 + "\n";
        }
    }
    //Conversion explicita a float
    else if (this->op == "tof"){
        this->auxVariable = tableSymbols->getAuxVariable();

        symbol * auxSymbol = new symbol(this->auxVariable, "", "float", "auxVariable");
        tableSymbols->insert(auxSymbol);

        out += "FILD " + op2 + "\n";
        out += "FSTP " + this->auxVariable + "\n";
    }

    //Si se trataba de una comparacion, no se devuelve el assembler + \n ya que lo siguiente que viene es el label.
    if (this->op == "==" || this->op == "<=" || this->op == "<" || this->op == ">=" || this->op == ">" || this->op == "!!")
        return out;
    else
        return out + "\n";
}

string Tercet::reemplazarEspacios(string s){
    for (int i = 0; i < s.length() - 1; i++){
        if (s[i] == ' '){
            s[i] = '_';
        }
    }
    return s;
}

Tercet::~Tercet(){
    
}