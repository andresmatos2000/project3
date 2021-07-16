//
// Created by munch on 7/12/2021.
//

#ifndef PROJECT1_INTERPRETER_H
#define PROJECT1_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include "Header.h"
#include "Tuple.h"
#include "Relation.h"
class Interpreter {
private:
    DatalogProgram* datalog;
    Database* database;
public:

    Interpreter(DatalogProgram* datalog){
        this->datalog = datalog;
        this->database = new Database();
        createDatabase();
    };
    Relation* evaluatePredicate(Predicate* p);
    void createDatabase();
};

void Interpreter::createDatabase(){
    //std::cout << "Creating database" << std::endl;
    for(auto i: datalog->Schemes){
//        std::cout << i->getName();
        Header* header = new Header(i);
        Relation* relation = new Relation(i->getName(),header);
        database->addRelation(i->getName(),relation);
    };
    for(auto i: datalog->Facts){
        std::vector<std::string> temp;
        for(auto j: i->getParameters()){
            temp.push_back(j->getValue());
        }
        database->addFactsToRelation(i->getName(),Tuple(temp));
    };
    for(auto i: datalog->Queries){
        evaluatePredicate(i);
    };
}

Relation* Interpreter::evaluatePredicate(Predicate* predicate) {

    Relation* relation = database->getRelation(predicate->getName());
    std::map<int, std::string> constants;
    std::map<int, std::string> variables;
    int j = 0;
    for(auto i : predicate->getParameters()){
        if(i->is_Constant()) {
            constants.insert(std::pair<int,std::string>(j,i->getValue()));
        }
        else{
            variables.insert(std::pair<int,std::string>(j,i->getValue()));
        }
        j++;
    };
    std::vector<int> recordedVariables;
    //Variable Select
    for(auto i: variables){
        int firstInstance;
        for(auto j: variables){
            if(i.first == j.first){
                firstInstance = i.first;
            } else {
                if(firstInstance < i.first) {
                    if (i.second == j.second) {
                        bool tobreak = false;
                        for(auto k : recordedVariables){
                            if (k == i.first)
                                tobreak = true;
                        }
                        if(tobreak)break;
                        recordedVariables.push_back(i.first);
                        relation = relation->select(relation,firstInstance,i.first);
                        //std::cout << "Call select" << i.first << i.second;

                    }
                }
            };

        }
    }
    //Constant Select
    for(auto i: constants){
        relation = relation->select(relation,i.second,i.first);
    }

    //RENAME
    relation = relation->rename(relation,variables);

    //PROJECT
    relation = relation->project(relation,variables);


    if(relation->getSize() > 0) {
        std::cout << predicate->To_String() + "? Yes(" + std::to_string(relation->getSize()) + ")" << std::endl;
    }
    else
        std::cout << predicate->To_String() + "? No" << std::endl;
relation->toString(variables.size());
    return relation;
};
#endif //PROJECT1_INTERPRETER_H
