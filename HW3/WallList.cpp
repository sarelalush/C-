//
// Created by sarel on 04/05/2021.
//

#include "WallList.h"
#include <stdio.h>

WallList::WallList() {
    head = NULL;
    curr = NULL;
}

bool WallList::addWall(Wall &wall) {
    curr = head;
    if(head == NULL)
    {
        head = &wall;
        listSize =1;
        return true;
    }
    while(curr->getNext())
    {
        curr = curr->getNext();
    }
    curr->setNext(wall);
    listSize++;
    return true;
}

int WallList::size() {
    return listSize;
}

Wall* WallList::getFirst() {
    return head;
}

WallList::~WallList() {
    curr = head;
    Wall * tmp = head;
    while(curr){
        curr = curr->getNext();
        delete tmp;
        tmp = curr;
    }
}

Wall* WallList::operator[](int index) {
    if(index < size())
    {
        curr = head;
        for(int i = 0; i < index; i++)
        {
            curr = curr->getNext();
        }
        return curr;
    }
    return NULL;
}