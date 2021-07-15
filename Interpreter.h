//
// Created by munch on 7/12/2021.
//

#ifndef PROJECT1_INTERPRETER_H
#define PROJECT1_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include "Header.h"
#include "Relation.h"
class Interpreter {
private:
    DatalogProgram* datalog;
    Database* database;
public:

    Interpreter(DatalogProgram* datalog){
        this->datalog = datalog;
        createDatabase();
    };

    void createDatabase();
};

void Interpreter::createDatabase(){
    std::cout << "Creating database";
    for(auto i: datalog->Schemes){
        std::cout << i->getName();
        Header* header = new Header(i->getName());
        Relation* relation = new Relation(i->getName(),header);
        database->addRelation(i->getName(),relation);
    };
};
#endif //PROJECT1_INTERPRETER_H
