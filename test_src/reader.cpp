#include <fstream>
#include <iostream>

#include "proto/test.pb.h"

void parse_msg(const pkg::helloworld &msg) {
    // 对于string变量的使用方法
    std::cout << "name: " << msg.student_name() << std::endl;

//    // 对于repeated int32变量的使用方法
//    for (int i = 0; i < msg.school_id_size(); ++i) {
//        std::cout << msg.school_id(i) << std::endl;
//    }

    std::cout << "school_id: ";
    for (auto item : msg.school_id()) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;

    // 对于子message变量的使用方法
    std::cout << msg.submess().name() << std::endl;
    std::cout << msg.submess().age() << std::endl;

    // 对于枚举类变量的使用方法
    std::cout << msg.day() << std::endl;
}

int main(int argc, char *argv[]) {
    pkg::helloworld msg1;

    {
        std::fstream input("./xxx_out", std::ios::in | std::ios::binary);
        if (!msg1.ParseFromIstream(&input)) {
            std::cerr << "Failed to read data." << std::endl;
            return -1;
        }
    }

    parse_msg(msg1);
}
