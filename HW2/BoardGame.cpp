//
// Created by sarel on 05/04/2021.
//


#include "BoardGame.h"
#include "Disks.h"
#include <iostream>
#include <iomanip>
using namespace std;

BoardGame::BoardGame(int seed){
    board[12].setNumberOfDisks(5) ;
    board[12].setColorOfDisks(White);
    board[8].setNumberOfDisks(3);
    board[8].setColorOfDisks(Black);
    board[6].setNumberOfDisks(5) ;
    board[6].setColorOfDisks(Black);
    board[1].setNumberOfDisks(2);
    board[1].setColorOfDisks(White);
    board[24].setNumberOfDisks(2) ;
    board[24].setColorOfDisks(Black);
    board[19].setNumberOfDisks(5);
    board[19].setColorOfDisks(White);
    board[17].setNumberOfDisks(3);
    board[17].setColorOfDisks(White);
    board[13].setNumberOfDisks(5) ;
    board[13].setColorOfDisks(Black);

    board[25].setNumberOfDisks(0);
    board[25].setColorOfDisks(White);
    board[26].setNumberOfDisks(0) ;
    board[26].setColorOfDisks(Black);

    X = seed;
    MostDisksUpper = 5;
    MostDisksLower = 5;
}

void BoardGame::printBoard(colorDisk diskType){
    Disks copyBoard[27];
    createCopyBoard(copyBoard);
    for (int i = 0; i < MostDisksUpper+1; ++i) {//upperBoard
        for (int j = 12; j >=1 ; --j) {
            if(j== 6 && i!=0){
                if(copyBoard[25].getNumberOfDisks() >0 )
                    cout<<" +W+ ";
                else
                    cout<<" + + ";
                copyBoard[25].decNumberOFDisks();
            }
            else if(j==12&& i!=0)
                cout<<"+ ";
            if(i>0 && i< MostDisksUpper+1 ) {
                setUpperDisk(j,copyBoard);
            }
            if (j==1 && i!=0)
                cout<<" +";
        }
        if(i==0) {
            if(diskType == Black)
                cout << " 12 11 10  9  8  7     6  5  4  3  2  1";
            else
                cout << " 13 14 15 16 17 18    19 20 21 22 23 24";
            cout << endl << "+------------------+-+------------------+" << endl;
        }
        else
            cout<<endl;
    }
    cout<<"+                  + +                  +"<<endl;
    for (int i = 0; i <MostDisksLower; i++) { //bottomBoard
        for (int j =  13; j <= 24; ++j) {
            if(j==13&&i!=MostDisksLower+1)
                cout<<"+ ";

            setBottomDisk(i,j,MostDisksLower,copyBoard);

            if(j== 18 && i != (MostDisksLower+1)){
                if(copyBoard[26].getNumberOfDisks() > 0 && copyBoard[26].getNumberOfDisks()>=(MostDisksLower-i)) {
                    cout << " +B+ ";
                    copyBoard[26].decNumberOFDisks();
                }
                else
                    cout<<" + + ";

            }
            if (j==24&&i!=(MostDisksLower+1))
                cout<<"+";

        }
        if(i==MostDisksLower-1) {
            cout << endl << "+------------------+-+------------------+" << endl;
            if(diskType == Black)
                cout<<" 13 14 15 16 17 18    19 20 21 22 23 24"<<endl;
            else
                cout << " 12 11 10  9  8  7     6  5  4  3  2  1"<<endl;

        }
        else
            cout<<endl;
    }

}

void BoardGame::setUpperDisk(int index,Disks copyBoard[26]){
    if(copyBoard[index].getNumberOfDisks()) {
        if (copyBoard[index].getColorOfDisks() == Black) {
            if (index == 1)
                cout << "B" << setw(2);
            else
                cout << "B" << setw(3);
        } else if (copyBoard[index].getColorOfDisks() == White) {
        if (index == 1)
            cout << "W" << setw(2);
        else
            cout << "W" << setw(3);
    }
        copyBoard[index].decNumberOFDisks();
    }
    else
    if(index==1)
        cout << "|" <<setw(2);
    else
        cout << "|" <<setw(3);
}

void BoardGame::setBottomDisk(int i, int j, int disks ,Disks copyBoard[26]) {
    if (copyBoard[j].getNumberOfDisks()) {
        if ((disks-i) <= copyBoard[j].getNumberOfDisks()) {
            if (copyBoard[j].getColorOfDisks() == Black) {
                if (j == 24)
                    cout << "B" << setw(2);
                else
                    cout << "B" << setw(3);
            }
            else if (board[j].getColorOfDisks() == White) {
                if (j == 24)
                    cout << "W" << setw(2);
                else
                    cout << "W" << setw(3);
            }
            copyBoard[j].decNumberOFDisks();
        }
        else {
            if (j == 24)
                cout << "|" << setw(2);
            else
                cout << "|" << setw(3);
        }
    }
    else {
        if (j == 24)
            cout << "|" << setw(2);
        else
            cout << "|" << setw(3);
    }
}
void BoardGame::createCopyBoard(Disks copyBoard[27])const
{
    for (int i = 0; i < 27; ++i) {
        copyBoard[i] = board[i];
    }
}
int BoardGame::getRndNumber(){
    const unsigned int a = 22695477;
    const unsigned int c = 1;
    X = a*X + c;
    return (((X & 0x7fffffff) >> 16) % 6) +1;
}
colorDisk BoardGame::whoStart(){
    int dice1 = 0 , dice2 = 0;
    while(dice1 == dice2){
        dice1 = getRndNumber();
        dice2 = getRndNumber();
        cout << "White player casts "<<dice1<<", black player casts "<<dice2 << endl;
    }
    return dice1> dice2 ? White : Black;
}
bool BoardGame::checkWinner(colorDisk player){
    for (unsigned int i = 1; i < 27; ++i) {
        if (board[i].getColorOfDisks() == player && board[i].getNumberOfDisks() > 0) {
            return false;
        }
    }
    return true;
}

bool BoardGame::checkValidMove(int from,int to,colorDisk player ,int &dice1 , int &dice2 ){
    int captive_index = (player == Black) ? 26 : 25;
    int sumFromTo = from-to;
    int realFrom = from;
    int realTo = to;
    from = player == Black ? from : 25-from;
    to = player == Black ? to : 25 -to;
    from = (realFrom>24) ? player == White ? 25 : 26 : from;
    to = (realTo == 0) ? 0 : to;

    if(from <0 || from >26 )
    {
        cout << "Illegal move: From/to out of bounds (from="<<realFrom<<", to="<<realTo<<")"<<endl;
        return false;
    }
    else if(to <0 || to >25 )
    {
        cout << "Illegal move: From/to out of bounds (from="<<realFrom<<", to="<<realTo<<").";
        return false;
    }
    else if(!(sumFromTo && sumFromTo <=6))
    {
        cout << "Illegal move: From/to out of bounds (from="<<realFrom<<", to="<<realTo<<")."<<endl;
        return false;
    }
    else if(board[captive_index].getNumberOfDisks() > 0 && realFrom !=25 && realFrom != 26)
    {
        cout << "Illegal move: Player still has captured piece(s)."<<endl;
        return false;
    }
    else if(board[from].getNumberOfDisks() == 0 ){
        cout << "Illegal move: No pieces at from location " << realFrom <<"."<<endl;
        return false;
    }
    else if(board[to].getColorOfDisks() != player && board[to].getNumberOfDisks() > 1){
        cout<<"Illegal move: Cannot capture more that one piece at location "<< realTo <<"."<<endl;
        return false;
    }
    else if(to == 0 && !checkAllPicecAtHome(player)){
        cout <<"Illegal move: Cannot bear off while not all pieces at home."<<endl;
        return false;
    }
    else if(checkAllPicecAtHome(player) && to == 0 && (dice1>= sumFromTo || dice2 >= sumFromTo)) {
        return true;
    }
    else if(sumFromTo != dice1 && sumFromTo != dice2 ){
        cout<<"Illegal move: No value of " << sumFromTo << " in dice roll "<<endl;
        return false;
    }
    return true;
}

bool BoardGame::checkAllPicecAtHome(colorDisk player){
    if(board[25].getNumberOfDisks() >0 || board[26].getNumberOfDisks()>0)
        return false;
    if(player == Black)
        for (unsigned int i = 7; i < 25; ++i) {
            if (board[i].getColorOfDisks() == player && board[i].getNumberOfDisks() > 0)
                return false;
        }
    else {
        for (unsigned int i = 18; i > 0; --i) {
            if (board[i].getColorOfDisks() == player && board[i].getNumberOfDisks() > 0)
                return false;
        }
    }

    return true;
}

void BoardGame::moveDisk(int from ,int to,int &dice1,int &dice2 , colorDisk player) {
    int sumFromTo = from-to;
    int realTo = to;
    int realFrom = from;
    from = player == Black ? from : 25-from;
    to = player == Black ? to : 25 -to;
    from = realFrom>24 ? player == White ? 25 : 26 : from;
    to = (realTo == 0) ? 0 : to;


    if(board[to].getNumberOfDisks() == 1 && board[to].getColorOfDisks() !=  board[from].getColorOfDisks() &&
    board[to].getColorOfDisks() == Black) {
        board[to].setColorOfDisks(board[from].getColorOfDisks());
        board[to].decNumberOFDisks();
        board[26].incNumberOfDisks();
    }
    else if(board[to].getNumberOfDisks() == 1  && board[to].getColorOfDisks() !=  board[from].getColorOfDisks() &&
    board[to].getColorOfDisks() == White) {
        board[to].setColorOfDisks(board[from].getColorOfDisks());
        board[to].decNumberOFDisks();
        board[25].incNumberOfDisks();
    }
    if(checkAllPicecAtHome(player) && to == 0 && (dice1>= sumFromTo || dice2 >= sumFromTo)){
        board[from].decNumberOFDisks();
    }
    else if (dice1 == sumFromTo) {
        board[from].decNumberOFDisks();
        board[to].incNumberOfDisks();
        board[to].setColorOfDisks(board[from].getColorOfDisks());
        dice1 = 0;
    }
    else {
        board[from].decNumberOFDisks();
        board[to].incNumberOfDisks();
        board[to].setColorOfDisks(board[from].getColorOfDisks());
        dice2 = 0;
    }
    board[0].setNumberOfDisks(0);
    changeBoardSize(realTo);
}

void BoardGame::changeBoardSize(int to){
    if(board[25].getNumberOfDisks() > MostDisksUpper)
        setMostDisksUpper(board[25].getNumberOfDisks());
    else if(board[26].getNumberOfDisks() > MostDisksLower)
        setMostDisksLower(board[26].getNumberOfDisks());
    int big = 5;
    for (int i = 1; i < 13; ++i) {
        if(board[i].getNumberOfDisks() > big)
            big = board[i].getNumberOfDisks();
    }
    setMostDisksUpper(big);
    big = 5;
    for (int i = 13; i < 25; ++i) {
        if(board[i].getNumberOfDisks() > big)
            big = board[i].getNumberOfDisks();
    }
    setMostDisksLower(big);
}

bool BoardGame::checkForMoreMoves(int dice1 , int dice2 , colorDisk player){
    if(checkWinner(player))
        return false;
    if(player == Black)
    {
        if(board[26].getNumberOfDisks() > 0){
            if(25-dice1 <25 && board[25-dice1].getColorOfDisks() == Black ) {
                return true;
            }
            else if(25-dice2 <25 && board[25-dice2].getColorOfDisks() == Black) {
                return true;
            }
            else if(dice1 != 0 && board[25-dice1].getColorOfDisks() == Black && board[25-dice1].getNumberOfDisks() <= 1){
                return true;
            }
            else if(dice2 != 0 && board[25-dice2].getColorOfDisks() == Black&&board[25-dice2].getNumberOfDisks() <= 1){
                return true;
            }
            return false;
        }
        for (int i = 24; i > 1; --i) {
            if( i-dice1 < 0 || i -dice2 <0)
            {
                if(checkAllPicecAtHome(player))
                    return true;
            }
            else if(board[i].getColorOfDisks() == Black ) {
                if ((board[i - dice1].getColorOfDisks() == Black || board[i - dice1].getColorOfDisks() <= 1)
                    || (board[i - dice2].getColorOfDisks() == Black || board[i - dice2].getColorOfDisks() <= 1)) {
                    return true;
                }
            }
        }
    }
    else{
        if(board[25].getNumberOfDisks() > 0){
            if(25-dice1 <25 && board[dice1].getColorOfDisks() == White) {
                return true;
            }
            else if(25-dice2 <25 && board[dice2].getColorOfDisks() == White) {
                return true;
            }
            else if(dice1 != 0 && board[dice1].getColorOfDisks() == Black && board[dice1].getNumberOfDisks() <= 1){
                return true;
            }
            else if(dice2 != 0 && board[dice2].getColorOfDisks() == Black&&board[dice2].getNumberOfDisks() <= 1){
                return true;
            }
            return false;
        }
        for (int i = 1; i < 24; ++i) {
            if(i+dice1 > 24 || i +dice2 >24)
            {
                if(checkAllPicecAtHome(player))
                    return true;
            }
            else if(board[i].getColorOfDisks() == White ){
                if((board[i+dice1].getColorOfDisks() == White || board[i+dice1].getColorOfDisks() <=1)
                    || (board[i+dice2].getColorOfDisks() == White || board[i+dice2].getColorOfDisks() <=1)){
                return true;
                }
            }

        }
    }
    return false;
}
int BoardGame::getMostDisksUpper()const{
    return this->MostDisksUpper;
}
void BoardGame::setMostDisksUpper(int diskNumber){
    this->MostDisksUpper = diskNumber;
}
int BoardGame::getMostDisksLower()const{
    return this->MostDisksLower;
}
void BoardGame::setMostDisksLower(int diskNumber){
    this->MostDisksLower = diskNumber;
}