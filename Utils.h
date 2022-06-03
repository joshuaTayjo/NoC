//
// Created by Josh Martinez on 5/23/22.
//

#ifndef NOC_UTILS_H
#define NOC_UTILS_H

#include "PVector.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Utils {

public:
    static std::vector<PVector> calcCubicBezier(const PVector& start, const PVector& end, const PVector& startControl, const PVector& endControl, size_t numSegments);
    static sf::Vector2f convertPVecToSFVec(const PVector& pVec);
    static float lerp(float, float, float);
    static PVector lerp(const PVector&, const PVector&, float);
};


#endif//NOC_UTILS_H
