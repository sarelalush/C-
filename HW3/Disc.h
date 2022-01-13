//
// Created by sarel on 03/05/2021.
//

#ifndef HW3_DISC_H
#define HW3_DISC_H
#include "Vector2D.h"
#include "Wall.h"

class Disc {
public:
    //ctor
    Disc(double x, double y, double vx, double vy, double r);
    /* big three */
    Disc(const Disc& other);

    Disc(Vector2D p, Vector2D v, double r, double m);

    virtual Disc& operator=(const Disc& rhs);
    virtual ~Disc();

    //get the next element
    Disc* getNext();
    //set the next element
    void setNext(Disc& disc);
    //update location by deltaTime
    void updateLocation(double dt);
    //check for Collision Disk to Disk (the real check)
    bool checkForCollisionDisks(Disc& disc2);
    //check for Collision Disk to Wall (the real check)
    bool checkForCollisionDiskAndWall(Wall& wall);
    //return the closest point from disk to wall
    Vector2D closestPoint(Wall& wall);
    //update speed of disks after collision (disk to disk)
    void updateSpeedAfterCollisionDisks(Disc& disc);
    //update speed of disk after collision (disk to Wall)
    void updateSpeedAfterCollisionWall(Wall& wall);
    //print Disk Location format (X,Y)
    void print();
    //return the X of location Vector
    double getX();
    //return the Y of location Vector
    double getY();
    //set the Loction
    void setXY(double x , double y);
    //return the Location Vector (by Vector)
    const Vector2D &getV2D() const;
    //set the Location Vector (by Vector)
    void setV2D(const Vector2D &v2D);
    //return the Speed Vector (by Vector)
    const Vector2D &getV2DSpeed() const;
    //set the speed Vector (by Vector)
    void setV2DSpeed(const Vector2D &v2DSpeed);
    //get Radius
    double getR() const;
    //get Mass
    double getM() const;
    //check for collison
    virtual bool getisCollision() const;
    //set after collison
    virtual void setIsCollision(bool isCollision);
    void removeNext();
protected:
        Disc * next;
        Vector2D v2d;
        Vector2D v2dSpeed;
        double r,m;
public:
    //set the radius
    void setR(double r);
    //set the Mass
    void setM(double m);

public:
    //get alive counter
    virtual int getAlive() const;
    //decrement the alive counter
    virtual void decAlive();
    //set alive counter
    virtual void setAlive(int alive);

protected:
    bool isCollision ;
    int alive;

};

#endif //HW3_DISC_H
