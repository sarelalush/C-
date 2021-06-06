//
// Created by sarel on 08/04/2021.
//

#include "Disks.h"


Disks::Disks(){
    this->color = Black;
    this->numberOfDisks = 0;
}

int Disks:: getNumberOfDisks()const{
    return this->numberOfDisks;
}
void Disks:: setNumberOfDisks(int num){
    this->numberOfDisks = num;
}
colorDisk Disks:: getColorOfDisks()const{
    return this->color;
}
void Disks:: setColorOfDisks(colorDisk color){
    this->color = color;
}
void Disks:: incNumberOfDisks(){
    this->numberOfDisks++;
}
void Disks:: decNumberOFDisks(){
    this->numberOfDisks--;
}