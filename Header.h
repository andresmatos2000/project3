//
// Created by munch on 7/12/2021.
//

#ifndef PROJECT1_HEADER_H
#define PROJECT1_HEADER_H
#include <vector>

class Header {
private:
    std::vector<std::string> headerList;
public:
    Header(std::string name){
        for(auto i: name){
            std::string s(1, i);
           headerList.push_back(s);
        };
    };
    void addHeader(std::string name);
    void toString();
    std::string getValue(int i);

};

void Header::addHeader(std::string name) {
for( auto i : name){
    std::cout << i << std::endl;
};
};
void Header::toString(){
    for(auto i: headerList){
        std::cout << i + " ";
    }
}
std::string Header::getValue(int i){
    return headerList[i];
}
#endif //PROJECT1_HEADER_H
