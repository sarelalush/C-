//
// Created by sarel on 28/05/2021.
//

#ifndef HW3_EXPLODINGDISC_H
#define HW3_EXPLODINGDISC_H
#include "Disc.h"

class ExplodingDisc : public Disc{
    public:
        ExplodingDisc(double x, double y, double vx, double vy, double r);
        /* big three */
        ExplodingDisc(const ExplodingDisc& other);

        ExplodingDisc(Vector2D p, Vector2D v, double r, double m,int alive);

        ~ExplodingDisc();
        //check for collison
        virtual bool getisCollision() const;
        //set after collison
        virtual void setIsCollision(bool isCollision);
        virtual ExplodingDisc& operator=(const ExplodingDisc& rhs);
        virtual void decAlive();
        virtual void setAlive(int alive);
        virtual int getAlive() const;

};




#endif //HW3_EXPLODINGDISC_H
