//
// Created by sarel on 28/05/2021.
//

#include "ShrinkingDisc.h"

ShrinkingDisc::ShrinkingDisc(double x, double y, double vx, double vy, double r) : Disc(x, y, vx, vy, r) {
    alive = 3;
}

ShrinkingDisc::ShrinkingDisc(const ShrinkingDisc &other) : Disc(other) {
    alive = other.alive;
}

ShrinkingDisc &ShrinkingDisc::operator=(const ShrinkingDisc &rhs) {
    setV2D(rhs.getV2D());
    setV2DSpeed(rhs.getV2DSpeed());
    r = rhs.getR();
    m = rhs.getM();
    isCollision = false;
    next = 0;
    alive = rhs.alive;
    return *this;
}

ShrinkingDisc::~ShrinkingDisc() {

}

ShrinkingDisc::ShrinkingDisc(Vector2D p, Vector2D v, double r, double m,int alive) : Disc(p,v, r, m) {
    this->alive = alive;
}

void ShrinkingDisc::decAlive() {
    alive--;
}

void ShrinkingDisc::setAlive(int alive) {
    this->alive = alive;
}
bool ShrinkingDisc::getisCollision() const {
    return this->isCollision;
}

void ShrinkingDisc::setIsCollision(bool isCollision) {
    this->isCollision = isCollision;
}

int ShrinkingDisc::getAlive() const{
    return alive;
}
