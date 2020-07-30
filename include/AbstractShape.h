#ifndef EXAMPLE_ABSTRACTSHAPE_H
#define EXAMPLE_ABSTRACTSHAPE_H

class AbstractShape
{
private:
    //私有字段
    int edge;

public:
    //构造函数
    AbstractShape(int edge);

    //实例方法，子类继承后可以重用
    int getEdge();

    //纯虚函数，父类没有实现，调用时只会调用子类的实现
    virtual int calcArea()=0;
};

#endif //EXAMPLE_ABSTRACTSHAPE_H
