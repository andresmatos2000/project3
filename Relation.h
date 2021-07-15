//
// Created by munch on 7/12/2021.
//

#ifndef PROJECT1_RELATION_H
#define PROJECT1_RELATION_H
#include "Tuple.h"
#include "Header.h"
#include <set>
class Relation {
private:
    std::string name;
    Header* header;
    std::set<Tuple> Tuples;
public:
    void addTuple(Tuple tuple);
    void toString();
    Relation* selectIndex();
    Relation* selectValue();
    Relation* project();
    Relation* rename();

    Relation(std::string name, Header* header){
        this->name = name;
        this->header = header;
    };
};
void Relation::toString() {
    for(Tuple i : Tuples){
        for(unsigned int j = 0; j < i.values.size(); j++){
            if(j == i.values.size()-1)
                std::cout << header->getValue(j) + "=" + i.values[j];
            else
                 std::cout << header->getValue(j) + "=" + i.values[j] + ", ";
        };
        std::cout << std::endl;
    }
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

void Relation::addTuple(Tuple tuple) {
    Tuples.insert(tuple);
};
#endif //PROJECT1_RELATION_H
