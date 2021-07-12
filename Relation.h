//
// Created by munch on 7/12/2021.
//

#ifndef PROJECT1_RELATION_H
#define PROJECT1_RELATION_H
#include "Tuple.h"
#include <set>
class Relation {
private:
    std::string name;
    Header* header;
    set<Tuple> Tuples;
public:
    void addTuple(Tuple* tuple);
    std::string To_String();
    Relation* selectIndex();
    Relation* selectValue();
    Relation* project();
    Relation* rename();

    Relation::Relation(std::string name, Header* header){
        this->name = name;
        this->header = header;
        Tuples = {};
    };
};

int Relation::To_String() {

}

Relation *Relation::selectIndex() {
    return nullptr;
}

Relation *Relation::selectValue() {
    return nullptr;
}

Relation *Relation::project() {
    return nullptr;
}

Relation *Relation::rename() {
    return nullptr;
}

void Relation::addTuple(Tuple* tuple) {
    Tuples.insert(tuple);
};
#endif //PROJECT1_RELATION_H
