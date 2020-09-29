#include <fstream>
#include <iostream>
#include <google/protobuf/util/json_util.h>

#include "proto/test.pb.h"

void print_msg(pkg::helloworld msg) {
    std::cout << "name: " << msg.student_name() << std::endl;
    std::cout << "school_id: ";
    for (auto &item: msg.school_id()) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
    std::cout << "day: " << msg.day() << std::endl;
    std::cout << "submess: {name: " << msg.submess().name()
              << ", age: " << msg.submess().age() << "}" << std::endl;

}

void pb2json() {
    std::string json_string;

    // Create a msg.
    pkg::helloworld msg;
    msg.set_student_name("cxq");
    msg.add_school_id(1);
    msg.add_school_id(2);
    msg.set_day(pkg::helloworld_weekday_sunday);
    auto ptr = msg.mutable_submess();
    ptr->set_age(36);
    ptr->set_name("james");

    // Create a json_string from msg. [pb to json]
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    MessageToJsonString(msg, &json_string, options);

    // Print json_string.
    std::cout << json_string << std::endl;

    std::string str = json_string;
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::cout << str << std::endl;


    // Parse the json_string into msg2. [json to pb]
    pkg::helloworld msg2;
    google::protobuf::util::JsonParseOptions options2;
    JsonStringToMessage(json_string, &msg2, options2);

    std::cout << "--------------------" << std::endl;
    // Print the values of msg2.
    print_msg(msg2);

    pkg::helloworld msg3;
    google::protobuf::util::JsonParseOptions options3;
    JsonStringToMessage(str, &msg3, options3);
    std::cout << "--------------------" << std::endl;
    print_msg(msg3);

}


int main(int argc, char **argv) {
    pb2json();
    return 0;
}