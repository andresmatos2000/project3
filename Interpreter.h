//
// Created by munch on 7/12/2021.
//

#ifndef PROJECT1_INTERPRETER_H
#define PROJECT1_INTERPRETER_H
#include "DatalogProgram.h"
class Interpreter {
private:
    DatalogProgram* datalog;
    //Still need to crate database class Database*;

public:

    Interpreter::Interperter(DatalogProgram* datalog){
        this->datalog = datalog;
    }

};


#endif //PROJECT1_INTERPRETER_H
