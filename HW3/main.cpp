#include <iostream>
#include "Disc.h"
#include "Wall.h"
#include "WallList.h"
#include "Table.h"
#include "ExplodingDisc.h"
#include "ShrinkingDisc.h"
#include <iomanip>


using namespace std;
int main() {
    string command="";

    double x1 = 0 , y1 = 0 , x2 = 0 , y2 = 0 , vx = 0 , vy = 0 , radius =0;
    double t = 0 , dt = 0;
    DiscList* discsList = new DiscList();
    WallList* wallsList = new WallList();
    while (command!="simulate"){
        cin>>command;
        if(cin.fail()){
            cerr<<"Error: illegal input."<<endl;
            return 0;
        }
        if(command == "disc"){
            cin >> x1 >> y1 >> vx >> vy >> radius;
            Disc* disc = new Disc(x1, y1, vx, vy, radius);
            if(discsList->checkDetectedDisk(*disc)){
                cerr<<"Error: disc to disc collision detected in initial configuration"<<endl;
                delete disc;
                return 0;
            }
            else{discsList->addDisc(*disc);}
        }
        else if(command == "exploding_disc"){
            cin >> x1 >> y1 >> vx >> vy >> radius;
            Disc* disc = new ExplodingDisc (x1, y1, vx, vy, radius);
            if(discsList->checkDetectedDisk(*disc)){
                cerr<<"Error: disc to disc collision detected in initial configuration"<<endl;
                delete disc;
                return 0;
            }
            else{discsList->addDisc(*disc);}
        }
        else if(command == "shrinking_disc"){
            cin >> x1 >> y1 >> vx >> vy >> radius;
            Disc* disc = new ShrinkingDisc (x1, y1, vx, vy, radius);
            if(discsList->checkDetectedDisk(*disc)){
                cerr<<"Error: disc to disc collision detected in initial configuration"<<endl;
                delete disc;
                return 0;
            }
            else{discsList->addDisc(*disc);}
        }
        else if(command == "wall"){
            cin >> x1 >> y1 >> x2 >> y2 ;
            Wall* wall = new Wall(x1, y1, x2, y2);
            if(discsList->checkDetectedWall(*wall)){
                cerr<<"Error: disc to wall collision detected in initial configuration"<<endl;
                delete wall;
                return 0;
            }
            else{wallsList->addWall(*wall);}
        }
    }
    if(command == "simulate" && discsList->size()) {
        cin >> t >> dt;
        Table tableGame(dt, t, wallsList, discsList);
        tableGame.startGame();
    }
    else
        cerr<<"Error: illegal input."<<endl;
    delete wallsList;
    delete discsList;
    return 1;
}
