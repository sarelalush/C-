//
// Created by sarel on 04/05/2021.
//

#ifndef HW3_WALLLIST_H
#define HW3_WALLLIST_H

#include "Wall.h"

class WallList {
    private:
        Wall * head;
        Wall * curr;
        int listSize;
    public:
        //constructor
        WallList();
        //destructor
        ~WallList();
        //add Wall to Wall list
        bool addWall(Wall& wall);
        // return the size of wall
        int size();
        // get the first Wall in the list
        Wall* getFirst();
        //[] operator to run with indexs on the Walls
        Wall* operator[](int index);
};


#endif //HW3_WALLLIST_H
