//
// Created by sarel on 08/05/2021.
//

#ifndef HW3_TABLE_H
#define HW3_TABLE_H

#include "WallList.h"
#include "DiscList.h"

#include <iostream>

class Table {
    private:
        WallList* wallList;
        DiscList* discList;
        double deltaT;
        double t;
    public:
        //constructor
        Table(double deltaT , double t ,WallList* wallList , DiscList* discList);
        //print the list time of the simulation
        void print(double time);
        //start the simulation
        void startGame();

        void createNewDiskList();

    Disc *checkForType();

    Disc *checkForType(Disc *Checkdisc);
};


#endif //HW3_TABLE_H
