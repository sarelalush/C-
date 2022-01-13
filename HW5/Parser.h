#ifndef HW5_PARSER_H
#define HW5_PARSER_H

#include <vector>
#include "Counter.h"

class Parser {
public:
    Parser();
    ~Parser();
    void menu();
    bool intNameExist(string name);
    bool stringNameExist(string name);

    class ExceptionAlreadyExist { };
    class ExceptionNoCounterByName {
    public:
        string name;
        ExceptionNoCounterByName(string name) : name(name){}

    };
    class ExceptionNoFile {};

private:
    vector<Counter<int> > intList;
    vector<Counter<string> > stringList;
    string type;

    Counter<int> &getFromIntListByName(string name);
    Counter<string> &getFromStringListByName(string name);
};

#endif //HW5_PARSER_H
