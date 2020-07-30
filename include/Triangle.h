#include "AbstractShape.h"
#ifndef EXAMPLE_TRIANGLE_H
#define EXAMPLE_TRIANGLE_H

class Triangle: public AbstractShape
{
private:
    //私有字段
    int bottom;
    int height;

public:
    //构造函数
    Triangle(int bottom, int height);

    //重写父类同名方法，用于实现多态性
    int calcArea();
};

#endif //EXAMPLE_TRIANGLE_H
