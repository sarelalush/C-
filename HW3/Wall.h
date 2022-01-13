//
// Created by sarel on 03/05/2021.
//

#ifndef HW3_WALL_H
#define HW3_WALL_H

#include "Vector2D.h"

class Wall {
    private:
        Vector2D v2d1;
        Vector2D v2d2;
        Wall * next;
    public:
        //construcor
        Wall(double x1,double y1 ,double x2 ,double y2);
        //three Big
        Wall(const Wall & other);
        Wall& operator=(const Wall & other);
        ~Wall();
        //set the next item on this Disk (using for the linked list)
        void setNext(Wall& disc);
        //get the next item
        Wall* getNext();
        //return Point1 of the wall
        Vector2D &P1() ;
        //return Point2 of the wall
        Vector2D &P2() ;
};


#endif //HW3_WALL_H
