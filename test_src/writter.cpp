#include <fstream>
#include <iostream>

#include "proto/test.pb.h"


int main(void) {
    pkg::helloworld msg1;

    // 对于string变量的使用方法
    msg1.set_student_name("cxq");

    // 对于repeated int32的变量的使用方法
    msg1.add_school_id(1);
    msg1.add_school_id(2);
    msg1.add_school_id(3);
    msg1.add_school_id(4);
    msg1.add_school_id(5);

    // 对于枚举变量的使用方法
    msg1.set_day(pkg::helloworld_weekday_monday);

    // 对于sub message的使用方法，使用指针的方式来对变量进行修改
    auto ptr = msg1.mutable_submess();
    ptr->set_age(36);
    ptr->set_name("james");

    // Write the new date back to disk.
    std::fstream output("./xxx_out", std::ios::out | std::ios::trunc | std::ios::binary);

    if (!msg1.SerializeToOstream(&output)) {
        std::cerr << "Failed to write msg." << std::endl;
        return -1;
    }
    std::cout << "done" << std::endl;
    return 0;
}