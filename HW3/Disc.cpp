//
// Created by sarel on 03/05/2021.
//

#include "Disc.h"
#include <iostream>
#include <iomanip>
using namespace std;

Disc::Disc(Vector2D p, Vector2D v, double r, double m) :v2d(p) , v2dSpeed(v),r(r),m(m){

}
Disc::Disc(double x, double y, double vx, double vy, double r)
: v2d(x,y) , v2dSpeed(vx,vy),r(r) {
    m = (r*r);
    next = NULL;
    alive = 3;
    isCollision = false;
}

Disc::Disc(const Disc &other)
{
    v2dSpeed = other.getV2D();
    v2d = other.getV2DSpeed();
    r = other.r;
    m = other.m;
    alive = other.alive;
    isCollision = other.isCollision;;
    next = NULL;
}

Disc *Disc::getNext() {
    return next;
}

void Disc::setNext(Disc &disc) {
    next = &disc;
}

void Disc::updateLocation(double dt) {
    double x = v2d.getX() ;
    double y = v2d.getY() ;
    x += v2dSpeed.getX() * dt;
    y += v2dSpeed.getY() * dt;
    v2d.updateVector(x,y);
}

bool Disc::checkForCollisionDisks(Disc& disc2) {
    if((v2d - disc2.v2d).normal() <= (r + disc2.r))
        return true;
    return false;
}
bool Disc::checkForCollisionDiskAndWall(Wall& wall) {
    Vector2D q = closestPoint(wall);
    double p = (v2d - q).normal();
    if(p <= r )
        return true;
    return false;
}
Vector2D Disc::closestPoint(Wall& wall) {
    double a = 0;
    if(wall.P1() == wall.P2()) // segment has length zero
        return wall.P1();
    else {
        a = ((v2d - wall.P1()) * (wall.P2() - wall.P1())) /
            (((wall.P1() - wall.P2()).normal()) * ((wall.P1() - wall.P2()).normal()));
        // ∙ is the dot product operator
        if (a < 0)
            return wall.P1();
        else if (a > 1)
            return wall.P2();
        else
            return wall.P1() + ((wall.P2() - wall.P1())*a);
    }
}
void Disc::updateSpeedAfterCollisionDisks(Disc& disc){
    Vector2D d = (v2d - disc.v2d)/((v2d - disc.v2d).normal());
    Vector2D delta = d*((v2dSpeed-disc.v2dSpeed)* d);
    double n1 = (2*disc.m/(m+disc.m));
    double n2 = (2*this->m/(this->m+disc.m));
    v2dSpeed -= (delta*n1);
    disc.v2dSpeed +=  (delta*n2);
}
void Disc::updateSpeedAfterCollisionWall(Wall& wall){
    Vector2D q = closestPoint(wall);
    Vector2D d = (this->v2d-q)/((this->v2d - q).normal());
    this->v2dSpeed = v2dSpeed - (d*(2*(v2dSpeed*d)));
}

void Disc::print(){
    cout << " (" << fixed << getX() << ',' << fixed << getY() << ")""/"<<r;
}

double Disc::getX() {
    return v2d.getX();
}

double Disc::getY() {
    return v2d.getY();
}

void Disc::setXY(double x , double y) {
    v2d.updateVector(x,y);
}

const Vector2D &Disc::getV2D() const {
    return v2d;
}

void Disc::setV2D(const Vector2D &v2D) {
    v2d = v2D;
}

const Vector2D &Disc::getV2DSpeed() const {
    return v2dSpeed;
}

void Disc::setV2DSpeed(const Vector2D &v2DSpeed) {
    v2dSpeed = v2DSpeed;
}

Disc::~Disc() {

}


Disc &Disc::operator=(const Disc &rhs){
    setV2D(rhs.getV2D());
    setV2DSpeed(rhs.getV2DSpeed());
    r = rhs.r;
    m = rhs.m;
    next = NULL;
    alive = rhs.alive;
    isCollision = rhs.isCollision;
    return *this;
}

double Disc::getR() const {
    return r;
}

double Disc::getM() const {
    return m;
}

bool Disc::getisCollision() const {
    return isCollision;
}

void Disc::setIsCollision(bool isCollision) {
    Disc::isCollision = isCollision;
}

void Disc::setR(double r) {
    Disc::r = r;
}

void Disc::setM(double m) {
    Disc::m = m;
}

void Disc::removeNext() {
    next = NULL;
}

int Disc::getAlive() const {
    return 3;
}

void Disc::setAlive(int alive) {
    this->alive = alive;
}


