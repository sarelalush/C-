//
// Created by sarel on 03/05/2021.
//

#ifndef HW3_DISCLIST_H
#define HW3_DISCLIST_H

#include "Disc.h"
#include "WallList.h"
class DiscList {
    private:
        Disc * head ;
        Disc * curr ;
        int listSize;
    public:
        //constructor
        DiscList();
        //destructor
        ~DiscList();
        //add disk to diskList
        bool addDisc(Disc& disc);
        //run all disks and update the speed of disks if was Collision
        void updateAllDiscs( double dt , WallList& wallsList);
        //check for collision disc to disc
        bool checkDetectedDisk(Disc& disc);
        //check for collision disc to Wall
        bool checkDetectedWall(Wall &wall);
        //return the size of array
        int size()const;
        //print all discs {format :(X,Y)}
        void printAllDiscs();
        //return the first element in the list
        Disc *getFirst();
        //[] opertor for a comfortable run on the linked list
        Disc& operator[](int index);
        const Disc& operator[](int index)const;
};


#endif //HW3_DISCLIST_H
