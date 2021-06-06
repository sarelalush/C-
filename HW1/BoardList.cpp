//
// Created by sarel on 09/03/2021.
//

#include "BoardList.h"
#include <iostream>
#include <stdlib.h>

const char colors [] ={' ', '.','+','*','/','\\','|','-'};
using namespace std;

BoardList::BoardList() {
    head = NULL;
    curr = NULL;
}
int BoardList::getTheNumberCodeBySign(char ch){
    for (int i = 0; i < 7; ++i) {
        if(colors[i] == ch)
            return i;
    }
    return 0;
}
bool BoardList::add_board(string name , int rows , int cols) {
    nodePtr newBoard = new nodeBoard;
    newBoard->name = name;
    newBoard->rows = rows;
    newBoard->cols = cols;
    newBoard->next = NULL;
    newBoard->board = new char*[cols];
    for (int i = 0; i < rows; ++i) {
        newBoard->board[i] = new char[cols];
    }
    for (int i = 0; i <rows ; ++i) {
        for (int j = 0; j <cols ; ++j) {
            newBoard->board[i][j] = ' ';
        }
    }
    if (checkExist(name)){
        delete_board(name);
    }
    else if (head != NULL){
        curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newBoard;
    }
    else {
        head = newBoard;
    }

    return true;
}
bool BoardList::delete_board(string name) {
    nodePtr delPtr = NULL, tmp = NULL;
    curr = head;
    tmp = head;
    while(curr != NULL && curr->name != name){
        tmp = curr;
        curr = curr ->next;
    }
    if(curr == NULL){
        cout << "this Name not exist";
        delete delPtr;
    }
    else if(curr == head){
        head = head->next;
        delete curr;
    }
    else{
        delPtr = curr;
        curr = curr->next;
        tmp->next = curr;
        for (int i = 0; i < delPtr->rows; ++i) {
            delete delPtr->board[i];
        }
        delete delPtr->board;
        delete delPtr;
    }
    return true;
}
int BoardList::size(){
    int size =0;
    curr = head;
    while(curr != NULL){
        curr = curr->next;
        size++;
    }
    return size;
}
bool BoardList::checkExist(string name){
    curr = head;
    while(curr != NULL && curr->name != name)
        curr = curr->next;
    if(curr == NULL)
        return false;
    return true;
}

void BoardList::drawPoint(int x,int y,int colorNumber,string name){
    curr = head;
    while(curr != NULL && curr->name != name)
        curr = curr->next;
    if(x>=0 && x<curr->cols && y>=0 && y<curr->rows)
    {
       curr->board[y][x] = colors[colorNumber];
    }
}
void BoardList::drawLine(int x1, int y1,int x2, int y2, int colorNumber, string boardName){
    bool plotxy = false;
    if(abs(x2-x1) < abs(y2-y1)){
        swap(x1,y1);
        swap(x2,y2);
        plotxy = true;
    }
    if(x2<x1){
        swap(x1,x2);
        swap(y1,y2);
    }

    int dx = x2 - x1;
    int dy = ::abs(y2 - y1);
    int sy = (y2 - y1) > 0 ? 1 : -1; // sign(z) = 1 if z>0; -1 if z<0; 0 otherwise
    int e = -dx;
    int x = x1;
    int y = y1;
    while (x <= x2) {
        if(plotxy){
            drawPoint(y,x,colorNumber,boardName);
        }
        else{
            drawPoint(x,y,colorNumber,boardName);
        }
        x += 1;
        e += 2 * dy;
        if (e > 0) {
            y += sy;
            e -= 2 * dx;
        }
    }

}
void BoardList::drawCircle(int x1,int y1,int r,int colorNumber,string boardName){
    int x = 0, y = r;
    int d = 3 - 2 * r;
    plot8(x1,y1,x,y,colorNumber,boardName);
    while (y >= x) {
        x += 1;
        if (d > 0) {
            y -= 1;
            d += 4 * (x - y) + 10;
        } else {
            d += 4 * x + 6;
        }
        plot8(x1,y1,x,y,colorNumber,boardName);
    }

}
void BoardList::print(string name){
    curr = head;
    while(curr != NULL && curr->name != name)
        curr = curr->next;
    for (int i = 0; i < curr->rows; ++i) {
        for (int j = 0; j < curr->cols; ++j) {
            cout << curr->board[i][j];
        }
        cout << endl;
    }
}

void BoardList::plot8(int x1,int y1, int x,int y ,int colorNumber,string boardName){
    drawPoint(x1+y,y1+x,colorNumber,boardName);
    drawPoint(x1-y,y1-x,colorNumber,boardName);
    drawPoint(x1+y,y1-x,colorNumber,boardName);
    drawPoint(x1-y,y1+x,colorNumber,boardName);

    drawPoint(x1+x,y1+y,colorNumber,boardName);
    drawPoint(x1-x,y1-y,colorNumber,boardName);
    drawPoint(x1+x,y1-y,colorNumber,boardName);
    drawPoint(x1-x,y1+y,colorNumber,boardName);
}

void BoardList::fill(int x,int y,int colorNumber,string boardName){
    curr = head;
    while(curr != NULL && curr->name != boardName){
        curr = curr->next;
    }
    if(x<0 || y < 0 || x>=curr->cols || y>=curr->rows || curr->board[y][x] != colors[0]){
        return;
    }
    drawPoint(x,y,colorNumber,boardName);
    fill(x+1,y,colorNumber,boardName);
    fill(x-1,y,colorNumber,boardName);
    fill(x,y+1,colorNumber,boardName);
    fill(x,y-1,colorNumber,boardName);

}
void BoardList::stamp(int x1,int y1,string boardName,string secBoardName){
    nodePtr stampBoard = head;
    curr = head;
    while(curr != NULL && curr->name != boardName){
        curr = curr->next;
    }
    while(stampBoard != NULL && stampBoard->name != secBoardName){
        stampBoard = stampBoard->next;
    }
    for (int i = 0; i < stampBoard->rows; ++i) {
        for (int j = 0; j < stampBoard->cols; ++j) {
            drawPoint(i+x1,j+y1,getTheNumberCodeBySign(stampBoard->board[j][i]),boardName);
        }
    }
}
void BoardList::distructor(){
    curr = head;
    while(curr){
        head = head->next;
        delete curr;
        curr = head;
    }
}