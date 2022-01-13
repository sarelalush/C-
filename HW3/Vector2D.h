//
// Created by sarel on 03/05/2021.
//

#ifndef HW3_VECTOR2D_H
#define HW3_VECTOR2D_H


class Vector2D {
    private:
        double x , y;
    public:
        //three Big
        Vector2D(double x,double y);
        Vector2D();
        ~Vector2D();
        Vector2D& operator =  (const Vector2D& v2d);
        Vector2D(const Vector2D & v2d);
        //here All opertors
        Vector2D  operator +  (Vector2D v2d) const;
        Vector2D  operator -  (Vector2D v2d) const;
        double    operator *  (Vector2D v2d) const;
        Vector2D& operator += (const Vector2D& v2d);
        Vector2D& operator -= (const Vector2D& v2d);
        Vector2D& operator *= (const Vector2D &v2d);
        Vector2D operator  *  (double scalar)const;
        Vector2D operator /  (double scalar)const;
        bool      operator == (const Vector2D &v2d) const;
        //update the Vector
        void updateVector(double x_upd, double y_upd);
        //return the Noraml
        double normal() const;
        //get X from vector
        double getY() const;
        //get Y from vector
        double getX() const;

};


#endif //HW3_VECTOR2D_H
