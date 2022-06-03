//
// Created by Josh Martinez on 5/13/22.
//

#ifndef HELLOSFML_PVECTOR_H
#define HELLOSFML_PVECTOR_H


class PVector {

public:
    float y;
    float x;

    PVector();
    PVector(const PVector& p);
    PVector(float x_, float y_);
    float mag();
    void normalize();
    void limit(float max);
    static PVector random2D();
    PVector operator+(const PVector& pv);
    PVector operator+(const PVector& pv) const;
    PVector operator+=(const PVector& pv);
    PVector operator-(const PVector& pv);
    PVector operator-(const PVector& pv) const;
    PVector operator-=(const PVector& pv);
    PVector operator*(float scalar);
    PVector operator*=(float scalar);
    PVector operator/(float scalar);
    PVector operator/=(float scalar);
};

PVector operator*(float, const PVector&);


#endif//HELLOSFML_PVECTOR_H
