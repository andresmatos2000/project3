//
// Created by munch on 7/12/2021.
//

#ifndef PROJECT1_DATABASE_H
#define PROJECT1_DATABASE_H

#include <map>
#include "Interpreter.h"
#include "Relation.h"

class Database {
private:
//map from name to relation
std::map<std::string, Relation*> map;
std::vector<Relation*> relations;
public:
void addRelation(std::string name,Relation* relation);

};

void Database::addRelation(std::string name,Relation* relation) {
    relation->addTuple(Tuple({"TEST"}));
    relation->toString();
    relations.push_back(relation);
}

#endif //PROJECT1_DATABASE_H
