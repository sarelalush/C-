#include <iostream>
#include "BoardList.h"


using namespace std;
bool checkName(string str){
    for (unsigned int i = 0; i < str.length(); ++i) {
        if(!isdigit(str[i]) && !isalpha(str[i]))
            return false;
    }
    return true;
}

int main() {
    string boardName ,secBoardName,command;
    int rows , cols , colorNumber ,x1,x2,y1,y2,r;
    BoardList b;

    while(cin >> command) {
        rows =0, cols =0, colorNumber =0,x1=0,x2=0,y1=0,y2=0,r=0;
        if (command == "board") {
            cin >> boardName >> rows >> cols;
            if (cols <= 0 || rows <= 0) {
                cerr << "Board: number of rows and columns must be greater that zero" << endl;
                break;
            }
            else if (!isalpha(boardName[0]) ) {
                cerr << "Invalid board name '" << boardName <<"'"<< endl;
                break;
            }
            else if( !checkName(boardName)){
                cerr<<"Board named '"<<boardName<<"' not found "<<endl;
                break;
            }
            b.add_board(boardName, rows, cols);
        }

        else if (command == "plot") {
            cin >> boardName >> x1 >> y1 >> colorNumber;

            if (!isalpha(boardName[0]) || !checkName(boardName)) {
                cerr << "Invalid board name '" << boardName <<"'"<< endl;
                break;
            }
            else if (colorNumber < 0 || colorNumber > 7) {
                cerr << "Invalid color number " << colorNumber << endl;
                break;
            }
            else if (!b.checkExist(boardName)) {
                cerr << "Board named '" << boardName << "' not found" << endl;
                break;
            }
            b.drawPoint(x1, y1, colorNumber, boardName);
        }

        else if (command == "line") {
            cin >> boardName >> x1 >> y1 >> x2 >> y2 >> colorNumber;
            if (!isalpha(boardName[0]) || !checkName(boardName)) {
                cerr << "Invalid board name '" << boardName <<"'"<< endl;
                break;
            } else if (colorNumber < 0 || colorNumber > 7) {
                cerr << "Invalid color number " << colorNumber << endl;
                break;
            }
            if (!b.checkExist(boardName)) {
                cerr << "Board named " << boardName << "not found" << endl;
                break;
            }
            b.drawLine(x1, y1,x2, y2, colorNumber, boardName);
        }

        else if (command == "circle") {
            cin >> boardName >> x1 >> y1 >> r >> colorNumber;
            if (!b.checkExist(boardName)) {
                cerr << "Board named '" << boardName << "' not found" << endl;
                break;
            }
            else if (!isalpha(boardName[0]) || !checkName(boardName)) {
                cerr << "Invalid board name '" << boardName <<"'"<< endl;
                break;
            } else if (colorNumber < 0 || colorNumber > 7) {
                cerr << "Invalid color number " << colorNumber << endl;
                break;
            }
            else if(r<0){
                cerr << "Circle: radius must be non-negative" << endl;
                break;
            }
            b.drawCircle(x1,y1,r,colorNumber,boardName);
        }

        else if (command == "fill"){
            cin >> boardName >> x1 >> y1 >> colorNumber;
            if (!b.checkExist(boardName)) {
                cerr << "Board named '" << boardName << "' not found" << endl;
                break;
            }
            else if (!isalpha(boardName[0]) || !checkName(boardName)) {
                cerr << "Invalid board name '" << boardName <<"'"<< endl;
                break;
            } else if (colorNumber < 0 || colorNumber > 7) {
                cerr << "Invalid color number " << colorNumber << endl;
                break;
            }
            else if(colorNumber == 0){
                cerr << "FloodFill: cannot flood with the background color" << endl;
                break;
            }
            b.fill(x1,y1,colorNumber,boardName);
        }

        else if (command == "stamp"){
            cin >> boardName >> x1 >> y1 >> secBoardName;
            if (!b.checkExist(boardName)) {
                cerr << "Board named '" << boardName << "' not found" << endl;
                break;
            }
            else if (!isalpha(boardName[0]) || !checkName(boardName)) {
                cerr << "Invalid board name '" << boardName <<"'"<< endl;
                break;
            } else if (colorNumber < 0 || colorNumber > 7) {
                cerr << "Invalid color number " << colorNumber << endl;
                break;
            }
            b.stamp(x1,y1,boardName,secBoardName);
        }

        else if(command == "print") {
            cin >> boardName;
            if (!b.checkExist(boardName)) {
                cerr << "Board named '" << boardName << "' not found" << endl;
                break;
            }
            else if (!isalpha(boardName[0]) || !checkName(boardName)) {
                cerr << "Invalid board name '" << boardName <<"'"<< endl;
                break;
            }
            b.print(boardName);
        }

        else if(command == "quit" )
        {
            break;
        }

        else{
            cerr << "unknown command '" << command<<"'"<<endl;
            break;
        }
        cin.clear();
    }
    b.distructor();
    return 0;
}
