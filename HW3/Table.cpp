//
// Created by sarel on 08/05/2021.
//

#include "Table.h"
#include "ExplodingDisc.h"
#include "ShrinkingDisc.h"
#include <math.h>
#include <iostream>
#include <typeinfo>

using namespace std;
Table::Table(double deltaT, double time , WallList* wallList , DiscList* discList):deltaT(deltaT) , t(time) {
    this->discList = discList;
    this->wallList = wallList;
}

void Table::startGame() {
    cout<<fixed;
    cout.precision(4);
    for(double time = 0; time <=t; time+=deltaT)
    {
        print(time);
        discList->updateAllDiscs(deltaT,*wallList);
        createNewDiskList();
    }
}

void Table::print(double time) {
    if(time ==0) {
        cout.precision(0);
        cout << noshowpoint << time << ":";
    }
    else
        cout << noshowpoint << time << ":";
    cout.precision(4);
    discList->printAllDiscs();

    cout <<" "<< endl;
}

void Table::createNewDiskList() {
    DiscList* newDiscList = new DiscList();
    for (int i = 0; i < discList->size(); ++i) {

        Disc * nDisk = checkForType(&(*discList)[i]);

        if(!nDisk->getisCollision()){
            newDiscList->addDisc(*nDisk);
        }
        else if(typeid(*nDisk) == typeid(Disc)){
            nDisk->setIsCollision(false);
            newDiscList->addDisc(*nDisk);
        }
        else if(typeid(*nDisk) == typeid(ShrinkingDisc)){
            nDisk->setIsCollision(false);
            nDisk->decAlive();
            if(((ShrinkingDisc *)nDisk)->getAlive() > 0){
                Disc *new_ShrinkingDisc = new ShrinkingDisc(nDisk->getV2D(),nDisk->getV2DSpeed(),nDisk->getR()*0.9,nDisk->getM(),nDisk->getAlive());
                newDiscList->addDisc(*new_ShrinkingDisc);
            }
        }
        else if(typeid(*nDisk) == typeid(ExplodingDisc)){
            nDisk->setIsCollision(false);
            nDisk->decAlive();
            if(((ExplodingDisc *)nDisk)->getAlive() > 0){
                Vector2D p = nDisk->getV2D();
                Vector2D v = nDisk->getV2DSpeed();
                double c = 0.99;
                double rTag = (2 * sqrt(3) - 3) * c * nDisk->getR();
                double a = (4 - (2 * sqrt(3))) * nDisk->getR();

                double globalMass = nDisk->getM()/3;
                int cntAlive = nDisk->getAlive();

                //1st Disc
                Vector2D p0 = p+Vector2D(0,a);
                Vector2D v0 = v+Vector2D(0,1);
                Disc *d0 = new ExplodingDisc(p0,v0,rTag,globalMass,cntAlive);

                //2st Disc
                Vector2D p1 = p + Vector2D(nDisk->getR()-a,-a/2);
                Vector2D v1 = v + Vector2D(sqrt(3)/2,-0.5);
                Disc *d1 = new ExplodingDisc(p1,v1,rTag,globalMass,cntAlive);

                //3st Disc
                Vector2D p2 = p + Vector2D(-(nDisk->getR()-a),-a/2);
                Vector2D v2 = v + Vector2D(-sqrt(3)/2,-0.5);
                Disc *d2 = new ExplodingDisc(p2,v2,rTag,globalMass,cntAlive);


                newDiscList->addDisc(*d0);
                newDiscList->addDisc(*d1);
                newDiscList->addDisc(*d2);

            }


        }
    }
    discList = newDiscList;
}

Disc *Table::checkForType(Disc * Checkdisc) {
    Disc * nDisk;
    if(typeid(*Checkdisc)==typeid(ExplodingDisc)){
        nDisk = new ExplodingDisc(0,0,0,0,0);
        *nDisk = *Checkdisc;
    }
    else if(typeid(*Checkdisc)==typeid(ShrinkingDisc)){
        nDisk = new ShrinkingDisc(0,0,0,0,0);
        *nDisk = *Checkdisc;
    }
    else{
        nDisk = new Disc(0,0,0,0,0);
        *nDisk = *Checkdisc;
    }
    return nDisk;
}
