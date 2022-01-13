//
// Created by sarel on 03/05/2021.
//

#include "Wall.h"
#include <iostream>

Wall::Wall(double x1 , double y1 , double x2 , double y2)
: v2d1(x1,y1),v2d2(x2,y2)
{
    next = NULL;
}

Wall *Wall::getNext() {
    return next;
}

void Wall::setNext(Wall &disc) {
    next = &disc;
}

Vector2D & Wall::P1()  {
    return v2d1;
}

Vector2D & Wall::P2()  {
    return v2d2;
}

Wall &Wall::operator=(const Wall &other) {
    v2d1 = other.v2d1;
    v2d2 = other.v2d2;
    next = NULL;
    return *this;
}

Wall::Wall(const Wall &other) {
    v2d1 = other.v2d1;
    v2d2 = other.v2d2;
    next = NULL;
}

Wall::~Wall() {

}

