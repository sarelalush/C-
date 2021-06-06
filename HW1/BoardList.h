//
// Created by sarel on 09/03/2021.
//

#ifndef HW1_BOARDLIST_H
#define HW1_BOARDLIST_H
#include <iostream>
using namespace std;


class BoardList {
    private:
        struct nodeBoard{
            char ** board;
            int rows;
            int cols;
            string name;
            nodeBoard *next;
        };
        typedef struct nodeBoard* nodePtr;
        nodePtr head;
        nodePtr curr;

    public:
        //********************************************************//
        //constructor
        BoardList();
        //********************************************************//
        // add board to the list
        //input : board name , rows , cols
        //return : true if the board add to list and false if not
        bool add_board(string name , int rows , int cols);
        //********************************************************//
        // check if board exist in the list
        //input : board name
        //return : true if the board in the list and false if not
        bool checkExist(string name);
        //********************************************************//
        // delete board from the list
        //input : board name
        //return : true if the board deleted and false if not
        bool delete_board(string name);
        //********************************************************//
        // plot function draw point on the matrix
        //input : board name , x , y , color
        void drawPoint(int x,int y,int colorNumber,string name);
        //********************************************************//
        // line function draw line on the matrix this function call to plot function
        //input : board name , x1 , y1 , x2 , y2 , color
        void drawLine(int x1,int y1 ,int x2 , int y2,int colorNumber,string name);
        //********************************************************//
        // circle function draw circle on the matrix
        //input : board name , x , y , radius,  color
        void drawCircle(int x1,int y1,int r,int colorNumber,string boardName);
        //********************************************************//
        // plot8 function draw 8 points on the matrix use for circle function
        //input : board name , x1 , y1 , x2 , y2 , color
        void plot8(int x1,int y1, int x,int y ,int colorNumber,string boardName);
        //********************************************************//
        // fill function fill points on the matrix
        //this function fill all the empty places
        //input : board name , x , y , color
        void fill(int x,int y,int colorNumber,string boardName);
        //********************************************************//
        // stamp function stamp with another board
        //this function fill the dst board with the src board
        //input : Soruce Board Name , x , y , Destination Board Name
        void stamp(int x1,int y1,string boardName,string secBoardName);
        //********************************************************//
        // getSign function
        // this function get the char of specific index in the matrix and search
        // the right key(number)
        // return : the key
        //input : char charcter
        static int getTheNumberCodeBySign(char ch);
        //********************************************************//
        // print function draw the matrix
        //input : string name
        void print(string name);
        //********************************************************//
        // distructor function free all the memory
        //input : board name , x , y , color
        void distructor();
        //********************************************************//
        // size function
        //input : None
        //return the size of the list
        int size();
        //********************************************************//
};


#endif //HW1_BOARDLIST_H
