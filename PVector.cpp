//
// Created by Josh Martinez on 5/13/22.
//

#include "PVector.h"
#include <cmath>
#include <random>

PVector::PVector() {
    x = 0;
    y = 0;
}

PVector::PVector(float x_, float y_) {
    x = x_;
    y = y_;
}

PVector::PVector(const PVector& p) {
    x = p.x;
    y = p.y;
}

float PVector::mag() {
    return sqrt(x * x + y * y);
}

void PVector::normalize() {
    float m = this->mag();
    if (m != 0) *this /= m;
}

void PVector::limit(float max) {
    if (this->mag() > max) {
        float factor = this->mag() / max;
        x /= factor;
        y /= factor;
    }
}

PVector PVector::random2D() {
    PVector randVec(rand() % 100 - 50, rand() % 100 - 50);
    randVec.normalize();
    return randVec;
}


PVector PVector::operator+(const PVector& pv) {
    PVector newVec;
    newVec.x = x + pv.x;
    newVec.y = y + pv.y;
    return newVec;
}

PVector PVector::operator+=(const PVector& pv) {
    this->x += pv.x;
    this->y += pv.y;
    return *this;
}

PVector PVector::operator-(const PVector& pv) {
    PVector newVec;
    newVec.x = x - pv.x;
    newVec.y = y - pv.y;
    return newVec;
}

PVector PVector::operator-=(const PVector& pv) {
    this->x -= pv.x;
    this->y -= pv.y;
    return *this;
}

PVector PVector::operator*(float scalar) {
    PVector newVec;
    newVec.x = x * scalar;
    newVec.y = y * scalar;
    return newVec;
}

PVector PVector::operator*=(float scalar) {
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

PVector PVector::operator/(float scalar) {
    PVector newVec;
    newVec.x = x / scalar;
    newVec.y = y / scalar;
    return newVec;
}

PVector PVector::operator/=(float scalar) {
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}
PVector PVector::operator-(const PVector& pv) const {
    PVector newVec;
    newVec.y = y - pv.y;
    return newVec;
}
PVector PVector::operator+(const PVector& pv) const {
    PVector newVec;
    newVec.x = x + pv.x;
    newVec.y = y + pv.y;
    return newVec;
}
PVector operator*(float scalar, const PVector& pv) {
    PVector newVec;
    newVec.x = pv.x * scalar;
    newVec.y = pv.y * scalar;
    return newVec;
}
