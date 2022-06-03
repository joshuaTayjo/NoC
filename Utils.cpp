//
// Created by Josh Martinez on 5/23/22.
//

#include "Utils.h"

std::vector<PVector> Utils::calcCubicBezier(const PVector& start, const PVector& end, const PVector& startControl, const PVector& endControl, const size_t numSegments) {
    std::vector<PVector> ret;
    if (!numSegments) return ret;

    ret.push_back(start);
    float p = 1.f / (float) numSegments;
    float q = p;

    for (size_t i = 1; i < numSegments; i++, p += q) {
        ret.push_back(p * p * p * (end + 3.f * (startControl - endControl) - start) +
                      3.f * p * p * (start - 2.f * startControl + endControl) +
                      3.f * p * (startControl - start) + start);
    }
    ret.push_back(end);
    return ret;
}
sf::Vector2f Utils::convertPVecToSFVec(const PVector& pVec) {
    return {pVec.x, pVec.y};
}
float Utils::lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;// monotonic near t=1
}
PVector Utils::lerp(const PVector& a, const PVector& b, float t) {
    PVector newVec;
    newVec.x = Utils::lerp(a.x, b.x, t);
    newVec.y = Utils::lerp(a.y, b.y, t);
    return newVec;
}
