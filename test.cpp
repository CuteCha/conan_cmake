#include <iostream>
#include "include/Triangle.h"

void call_triangle() {
    Triangle triangle = Triangle(3, 4);
    std::cout << "edge=" << triangle.getEdge() << std::endl;
    std::cout << "area=" << triangle.calcArea() << std::endl;
}


int main(int argc, char **argv) {
    std::cout << "[Debug]" << std::endl;
    call_triangle();

    return 0;
}
