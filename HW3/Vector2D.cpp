//
// Created by sarel on 03/05/2021.
//

#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(double x, double y):x(x) , y(y) {}

Vector2D::Vector2D(const Vector2D& v2d) {
    x = v2d.x;
    y = v2d.y;
}

Vector2D Vector2D::operator+(Vector2D v2d) const{
    Vector2D new_vec(x+v2d.x , y+v2d.y);
    return new_vec;
}

Vector2D Vector2D::operator-(Vector2D v2d) const {
    Vector2D new_vec(x-v2d.x , y-v2d.y);
    return new_vec;
}

double Vector2D::operator*(Vector2D v2d) const{
    return (x * v2d.x) + (y * v2d.y) ;
}

Vector2D &Vector2D::operator+=(const Vector2D &v2d) {
    x = x + v2d.x;
    y = y + v2d.y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &v2d) {
    x = x - v2d.x;
    y = y - v2d.y;
    return *this;
}

Vector2D &Vector2D::operator*=(const Vector2D &v2d) {
    x = x * v2d.x;
    y = y * v2d.y;
    return *this;
}

Vector2D Vector2D::operator*(double scalar) const {
    Vector2D new_vec(getX() , getY());
    new_vec.x = new_vec.x * scalar;
    new_vec.y = new_vec.y * scalar;
    return new_vec;
}
Vector2D Vector2D::operator/(double scalar)const {
    Vector2D new_vec(x , y);
    new_vec.x = new_vec.x / scalar;
    new_vec.y = new_vec.y / scalar;
    return new_vec;
}

Vector2D &Vector2D::operator=(const Vector2D &v2d) {
    x = v2d.x;
    y = v2d.y;
    return *this;
}
bool Vector2D::operator==(const Vector2D &v2d) const {
    return x==v2d.x && y == v2d.y;
}
double Vector2D::normal() const{
    return sqrt((x*x)+(y*y));
}
void Vector2D::updateVector(double x_upd, double y_upd){
    this->x = x_upd;
    this->y = y_upd;
}

double Vector2D::getY() const {
    return this->y;
}

double Vector2D::getX() const {
    return this->x;
}

Vector2D::Vector2D() {

}

Vector2D::~Vector2D() {

}

