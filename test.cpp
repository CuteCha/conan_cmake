#include <iostream>
#include "include/Triangle.h"
#include "map"

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

void outputMap() {
    std::map<std::string, std::string> map;
    map["a"] = "100";
    map["c"] = "200";
    map["b"] = "300";

    if (!map.empty()) {
        for (auto iter = map.begin(); iter != map.end(); iter++) {
            std::cout << "k=" << iter->first << ", v=" << iter->second << std::endl;
        }
    }

    std::cout << "---------------map.size=" << map.size() << std::endl;

    for (auto &item: map) {
        std::cout << "k=" << item.first << ", v=" << item.second << std::endl;
    }

    if (map.find("a") != map.end()) {
        std::cout << "a=" << map.at("a") << std::endl;
    }

    if (map.find("d") != map.end()) {
        std::cout << "d=" << map.at("d") << std::endl;
    } else {
        std::cout << "d not in map" << std::endl;
    }

    if (map.count("d")) {
        std::cout << "d=" << map.at("d") << std::endl;
    } else {
        std::cout << "d not in map" << std::endl;
    }

    std::map<std::string, std::string> map1;
    std::cout << map1.count("a") << std::endl;


}

int main(int argc, char **argv) {
    std::cout << "[Debug]" << std::endl;
    call_triangle();
    aplusplus_test();
    outputMap();

    return 0;
}
