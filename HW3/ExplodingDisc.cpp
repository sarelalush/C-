//
// Created by sarel on 28/05/2021.
//

#include "ExplodingDisc.h"
#include <iostream>

ExplodingDisc::ExplodingDisc(double x, double y, double vx, double vy, double r) : Disc(x, y, vx, vy, r) {
    alive = 3;
}
ExplodingDisc::ExplodingDisc(Vector2D p, Vector2D v, double r, double m,int alive) : Disc(p,v, r, m) {
    this->alive = alive;
}
ExplodingDisc::ExplodingDisc(const ExplodingDisc &other) : Disc(other) {
    alive = other.alive;
}

ExplodingDisc &ExplodingDisc::operator=(const ExplodingDisc &rhs) {
    setV2D(rhs.getV2D());
    setV2DSpeed(rhs.getV2DSpeed());
    r = rhs.getR();
    m = rhs.getM();
    next = NULL;
    isCollision = false;
    alive = rhs.alive;
    return *this;
}

ExplodingDisc::~ExplodingDisc() {

}

void ExplodingDisc::setAlive(int alive) {
    alive = alive;
}

void ExplodingDisc::decAlive() {
    alive--;
}

bool ExplodingDisc::getisCollision() const {
    return this->isCollision;
}

void ExplodingDisc::setIsCollision(bool isCollision) {
    this->isCollision = isCollision;
}
int ExplodingDisc::getAlive() const{
    return alive;
}

