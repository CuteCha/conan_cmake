#include "../include/AbstractShape.h"
#include "../include/Triangle.h"

Triangle::Triangle(int bottom, int height) :
        AbstractShape(3)
{
    this->bottom = bottom;
    this->height = height;
}

int Triangle::calcArea()
{
    return this->bottom * this->height / 2;
}
