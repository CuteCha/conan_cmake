//
// Created by cxq on 2019/9/30.
//

#include "../include/AbstractShape.h"

AbstractShape::AbstractShape(int edge)
{
    this->edge = edge;
}

int AbstractShape::getEdge()
{
    return this->edge;
}