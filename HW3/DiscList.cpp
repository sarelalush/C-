//
// Created by sarel on 03/05/2021.
//

#include "DiscList.h"
#include <iostream>
#include "iomanip"
#include <stdlib.h>

using namespace std;
DiscList::DiscList(): listSize(0){
    head = NULL;
    curr = NULL;
}
bool DiscList::addDisc(Disc& disc) {
    curr = head;
    if(head == NULL) {
        head = &disc;
        listSize = 1;
        return true;
    }
    while (curr->getNext())
    {
        curr = curr->getNext();
    }
    curr->setNext(disc);
    listSize++;
    return true;
}

int DiscList::size()const{
    return listSize;
}
Disc* DiscList::getFirst() {
    return head;
}
void DiscList::updateAllDiscs(double dt , WallList& wallsList) {
    for (int i = 0; i < size(); ++i) {
        double xBefore = (*this)[i].getX();
        double yBefore = (*this)[i].getY();
        bool flag = false;
        (*this)[i].updateLocation(dt);
        for (int j = 0; j < size(); ++j) {
            if(i!=j)
            {
                if((*this)[i].checkForCollisionDisks((*this)[j])) {
                    (*this)[i].updateSpeedAfterCollisionDisks((*this)[j]);
                    (*this)[i].setIsCollision(true);
                    (*this)[j].setIsCollision(true);
                    flag = true;
                }
            }
        }
        for (int j = 0; j < wallsList.size(); ++j) {
            if((*this)[i].checkForCollisionDiskAndWall(*wallsList[j])) {
                (*this)[i].updateSpeedAfterCollisionWall(*wallsList[j]);
                flag = true;
                (*this)[i].setIsCollision(true);
            }
        }
        if(flag) {
            (*this)[i].setXY(xBefore, yBefore);
        }
    }
}

bool DiscList::checkDetectedDisk(Disc& disc) {
    curr = head;
    while(curr){
        if(curr->checkForCollisionDisks(disc))
        {
            return true;
        }
        curr = curr->getNext();
    }
    return false;
}

bool DiscList::checkDetectedWall(Wall &wall) {
    curr = head;
    while(curr){
        if(curr->checkForCollisionDiskAndWall(wall))//check
        {
            return true;
        }
        curr = curr->getNext();
    }
    return false;
}

DiscList::~DiscList() {
    curr = head;
    Disc * tmp = head;
    while(curr){
        curr = curr->getNext();
        delete tmp;
        tmp = curr;
    }

}

void DiscList::printAllDiscs() {
    curr = head;
    while(curr){
        curr->print();
        curr = curr->getNext();
    }
}


Disc& DiscList::operator [] (int index) {
    if(index < size() && index >=0)
    {
        curr = head;
        for(int i = 0; i < index; i++)
        {
            curr = curr->getNext();
        }
        return *curr;
    }
    exit(1);

}

const Disc &DiscList::operator[](int index) const {
    if(index < size() && index >=0)
    {
        Disc* temp = head;
        for(int i = 0; i < index; i++)
        {
            temp = temp->getNext();
        }
        return *temp;
    }
    exit(1);
}

void Disc::decAlive() {
    alive--;
}