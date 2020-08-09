#include <iostream>
#include "include/Triangle.h"

void call_triangle() {
    Triangle triangle = Triangle(3, 4);
    std::cout << "edge=" << triangle.getEdge() << std::endl;
    std::cout << "area=" << triangle.calcArea() << std::endl;
}

void aplusplus_test() {
    int a = 1;
    std::cout << a << std::endl;
    ++a = 7; // ++a 返回a   a自己先+1，再返回a来做后续的应用
    //a++ = 7; //先用a，使用完了再加1
    std::cout << a << std::endl;
    a = 1;
    int b = a++ + 1;
    std::cout << b << std::endl;
    a = 1;
    int c = ++a + 1;
    std::cout << c << std::endl;
}


int main(int argc, char **argv) {
    std::cout << "[Debug]" << std::endl;
    call_triangle();
    aplusplus_test();

    return 0;
}
