//
// Created by sarel on 28/05/2021.
//

#ifndef HW3_SHRINKINGDISC_H
#define HW3_SHRINKINGDISC_H
#include "Disc.h"

class ShrinkingDisc : public Disc {
    public:
        ShrinkingDisc(double x, double y, double vx, double vy, double r);
        /* big three */
        ShrinkingDisc(const ShrinkingDisc& other);

    ShrinkingDisc(Vector2D p, Vector2D v, double r, double m, int alive);

    virtual ShrinkingDisc& operator=(const ShrinkingDisc& rhs);
    virtual void decAlive();
    virtual void setAlive(int alive);
    virtual int getAlive() const;
    //check for collison
    virtual bool getisCollision() const;
    //set after collison
    virtual void setIsCollision(bool isCollision);

    ~ShrinkingDisc();

};


#endif //HW3_SHRINKINGDISC_H
