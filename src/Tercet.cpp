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
        op1 = "_" + this->arg1;
        symbol * firstArg = tableSymbols->getSymbol(this->arg1);
        if (firstArg)
            typeOfFirstArg = firstArg->type;     
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
            out += "FST " + this->auxVariable + "\n";
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
            out += "FST " + this->auxVariable + "\n";
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
            out += "FST " + this->auxVariable + "\n";
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
            out += "FST " + this->auxVariable + "\n";
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
            out += "FST " + op1 + "\n";
        }
    }
    //Comparacion igual
    else if (this->op == "=="){
        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JNE" + op1 + "\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JNE" + op1 + "\n";
        }
    }
    //Comparacion menor o igual
    else if (this->op == "<="){
        if (typeOfFirstArg == "short"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JG" + op1 + "\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JA" + op1 + "\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JG" + op1 + "\n";
        }
    }
    //Comparacion menor
    else if (this->op == "<"){
        if (typeOfFirstArg == "short"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JGE" + op1 + "\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JAE" + op1 + "\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JGE" + op1 + "\n";
        }
    }
    //Comparacion mayor o igual
    else if (this->op == ">="){
        if (typeOfFirstArg == "short"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JL" + op1 + "\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JB" + op1 + "\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JL" + op1 + "\n";
        }
    }
    //Comparacion mayor
    else if (this->op == ">"){
        if (typeOfFirstArg == "short"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JLE" + op1 + "\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JBE" + op1 + "\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JLE" + op1 + "\n";
        }
    }
    //Comparacion distinto
    else if (this->op == "!!"){
        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "CMP" + op1 + ", " + op2 + "\n";
            out += "JE" + op1 + "\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JE" + op1 + "\n";
        }
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
    out += "\n";
    return out;
}


Tercet::~Tercet(){
    
}