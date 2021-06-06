//
// Created by sarel on 05/04/2021.
//
#include "Disks.h"
#ifndef HW2_BOARDGAME_H
#define HW2_BOARDGAME_H

class BoardGame {
    private:
        Disks board [30];
        int MostDisksUpper;
        int MostDisksLower;
        int X ; //use for seed

    public:
        //constructor
        //set the seed value
        //set the start board locations
        //input : seed
        BoardGame(int startSeed);
        //printBoard
        //this function print the board
        //get the color disk and print the appropriate board
        //input : ColorDisk - to know which player is playing now
        void printBoard(colorDisk diskType) ;
        //setUpperDisk
        //this function print the specific upper index from array
        //input : the board and index
        void setUpperDisk(int index,Disks copyBoard[26]);
        //setBottomDisk
        //this function print the specific Bottom index from array
        //input : the board and index
        void setBottomDisk(int i,int j,int disks,Disks copyBoard[26]);
        //setBottomDisk
        //this function generate a random number
        //input : the board and index
        //output : random int number
        int getRndNumber();
        //This function decides who starts
        //input : None
        //output : the disk color of the start player
        colorDisk whoStart();
        //This function check if the player win the game
        //input : The player who is playing now
        //output : true if this player win | else - false
        bool checkWinner(colorDisk player);
        //This function check if the player move is Valid
        //input : from , to (from where to where) ,colorDisk to know who is the player play now
        //        and dice1 , dice2 to check if the move is valid
        //output : true if this Valid | else - false
        bool checkValidMove(int from,int to,colorDisk player,int &dice1,int &dice2);
        //This function check if the all player disks at home
        //input : playr color disk to know who is the player play now
        //output : true if all at home | else - false
        bool checkAllPicecAtHome(colorDisk player);
        //This function move the disk in the array
        //input : from , to (from where to where) ,colorDisk to know who is the player play now
        //        and dice1 , dice2 to know what move to make
        //input : bool true false
        void moveDisk(int from ,int to,int &dice1,int &dice2, colorDisk player);
        //This function change the size of the board
        //input : to index - to check if in this index the number of disks big than the current disks number
        void changeBoardSize(int to);
        //This important function check if the player currently playing have more moves
        //input : dices and the player who is play now
        //output : bool true false
        bool checkForMoreMoves(int dice1 , int dice2 , colorDisk player);

    public:
        //getter for MostDiskUpper value
        //input : None
        //output : the value - MostDiskUpper
        int getMostDisksUpper()const;
        //setter for MostDiskUpper value
        //input : Number of disks
        //output : None
        void setMostDisksUpper(int diskNumber);
        //getter for MostDisksLower value
        //input : None
        //output : the value - MostDisksLower
        int getMostDisksLower()const;
        //setter for MostDisksLower value
        //input : Number of disks
        //output : None
        void setMostDisksLower(int diskNumber);
        //this function copy the disks array of the this class to the copyArray
        //input : Array of Disks
        void createCopyBoard(Disks board [26])const;
};


#endif //HW2_BOARDGAME_H
