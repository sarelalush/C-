//
// Created by shai0 on 6/15/2021.
//
#include "Parser.h"
#include <fstream>
#include <stdlib.h>

Parser::Parser() {

}

Parser::~Parser() {

}

void Parser::menu() {
    string command;
    string nameToExecute;
    string file_name;
    string line;
    try {
        while (cin >> command) {
            if (cin.fail()) {
                throw ;
            }
            if (command == "string_counter") {
                cin >> nameToExecute;
                if (cin.fail()) {
                    throw Ex() ;
                }
                if (intNameExist(nameToExecute) || stringNameExist(nameToExecute))
                    throw ExceptionAlreadyExist();
                stringList.push_back(Counter<string>(nameToExecute, "string"));
            } else if (command == "int_counter") {
                cin >> nameToExecute;
                if (cin.fail()) {
                    throw;
                }
                if (intNameExist(nameToExecute) || stringNameExist(nameToExecute))
                    throw ExceptionAlreadyExist();
                intList.push_back(Counter<int>(nameToExecute, "int"));

            } else if (command == "add_from_file") {
                cin >> nameToExecute >> file_name;
                if (cin.fail()) {
                    throw 5;
                }
                if (intNameExist(nameToExecute) || stringNameExist(nameToExecute)) {

                    if (intNameExist(nameToExecute)) {
                        char *a = &file_name[0];
                        ifstream file(a);

                        if (!file.is_open()) {
                            throw ExceptionNoFile();
                        }
                        getFromIntListByName(nameToExecute).add_from_stream(file);

                    } else if (stringNameExist(nameToExecute)) {
                        char *a = &file_name[0];
                        fstream file(a);

                        if (!file.is_open()) {
                            throw ExceptionNoFile();
                        }
                        getFromStringListByName(nameToExecute).add_from_stream(file);
                    }
                } else { // Can't allocate the counter that refer to
                    throw ExceptionNoCounterByName(nameToExecute);
                }
            } else if (command == "add_from_string") {
                cin >> nameToExecute;
                if (!(intNameExist(nameToExecute) || stringNameExist(nameToExecute))) {
                    throw ExceptionNoCounterByName(nameToExecute);
                } else if (intNameExist(nameToExecute) || stringNameExist(nameToExecute)) {
                    if (intNameExist(nameToExecute)) {
                        string s;
                        getline(cin, s);
                        istringstream iss(s);
                        getFromIntListByName(nameToExecute).add_from_stream(iss);
                    } else if (stringNameExist(nameToExecute)) {
                        string s;
                        getline(cin, s);
                        istringstream iss(s);
                        getFromStringListByName(nameToExecute).add_from_stream(iss);
                    }
                }
            } else if (command == "stats") {
                cin >> nameToExecute;
                if (!(intNameExist(nameToExecute) || stringNameExist(nameToExecute))) {
                    throw ExceptionNoCounterByName(nameToExecute);
                } else if (intNameExist(nameToExecute) || stringNameExist(nameToExecute)) {
                    if (intNameExist(nameToExecute)) {
                        getFromIntListByName(nameToExecute).print_to_stream(cout);
                    } else if (stringNameExist(nameToExecute)) {
                        getFromStringListByName(nameToExecute).print_to_stream(cout);
                    }
                }

            } else if (command == "most_common") {
                cin >> nameToExecute;
                if (!(intNameExist(nameToExecute) || stringNameExist(nameToExecute))) {
                    throw ExceptionNoCounterByName(nameToExecute);
                } else if (intNameExist(nameToExecute) || stringNameExist(nameToExecute)) {
                    if (intNameExist(nameToExecute)) {
                        getFromIntListByName(nameToExecute).print_most_common(cout);
                    } else if (stringNameExist(nameToExecute)) {
                        getFromStringListByName(nameToExecute).print_most_common(cout);
                    }
                }
            }
            else{

            }


        }
    }
    catch (Counter<int>::ExceptionEmptyCount e){
        cerr << "Error: Counter is empty" << endl;
        exit(1);

    }
    catch (Counter<int>::ExceptionErrorWhileInput e){
        cerr << "Error: Read failed" << endl;
        exit(1);
    }
    catch (Counter<string>::ExceptionEmptyCount e){
        cerr << "Error: Counter is empty" << endl;
        exit(1);

    }
    catch (Counter<string>::ExceptionErrorWhileInput e){
        cerr << "Error: Read failed" << endl;
        exit(1);
    }
    catch (ExceptionAlreadyExist e){
        cerr << "Error: Counter name already exists" << endl;
        exit(1);
    }
    catch (ExceptionNoCounterByName e){
        cerr << "Error: No counter named " << e.name << endl;
        exit(1);
    }
    catch  (ExceptionNoFile e){
        cerr << "Error: Failed to open file" << endl;
        exit(1);
    }
    catch(int i){
        cerr << "Error: Missing file name" << endl;
        exit(1);
    }
    catch  (...){
        cerr << "Error: Unknown command this" << endl;
        exit(1);
    }

}

bool Parser::intNameExist(string name) {
    for (int i = 0; i < intList.size(); ++i) {
        if(intList[i].getName() == name)
            return true;
    }
    return false;
}

bool Parser::stringNameExist(string name) {
    for (int i = 0; i < stringList.size(); ++i) {
        if(stringList[i].getName() == name)
            return true;
    }
    return false;
}

Counter<int> &Parser::getFromIntListByName(string name) {
    for (int i = 0; i < intList.size(); ++i) {
        if(intList[i].getName() == name)
            return intList[i];
    }
}

Counter<string> &Parser::getFromStringListByName(string name) {
    for (int i = 0; i < stringList.size(); ++i) {
        if(stringList[i].getName() == name)
            return stringList[i];
    }
}