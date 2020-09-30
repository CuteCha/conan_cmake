#include <fstream>
#include <iostream>
#include <google/protobuf/util/json_util.h>

#include "proto/test.pb.h"
#include "proto/people.pb.h"

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

void pb2json2() {
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
//    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    MessageToJsonString(msg, &json_string, options);

    // Print json_string.
    std::cout << json_string << std::endl;

    /*
        add_whitespace
        (bool) 是否添加空格，换行符和缩进以使输出的JSON易于阅读。默认为false。

        always_print_primitive_fields
        (bool) 是否始终打印原始字段。默认情况下，具有默认值的原始字段将在JSON输出中被省略。例如，设置为0的int32字段将被省略。将此标志设置为true，将覆盖默认行为并打印原始字段，而不考虑其值。默认为false。

        always_print_enums_as_ints
        (bool) 是否始终打印枚举作为整数。默认情况下，它们呈现为字符串。默认为false。

        preserve_proto_field_names
        (bool) 是否保留原始字段名称。默认情况下，protobuf将使用json_name选项生成JSON字段名称，或者按照下面的顺序生成较低的骆驼风格的大小写。设置此标志将保留原始字段名称。默认为false。
      */

}

void pb2json3() {
    std::string json_string;

    // Create a msg.
    cxq_pkg::people person;
    person.set_name("cxq");
    person.set_id(19);
    person.add_favorite("basketball");
    person.add_favorite("fish");
    person.set_day(cxq_pkg::people_weekday_sunday);
    auto ptr = person.msg();
    ptr.set_age(30);
    ptr.set_address("bj");

//    auto pet = person.pet(0);
//    pet.set_name("dog");
//    pet.set_color("yellow");
//
//    auto pet2 = person.pet(1);
//    pet2.set_name("cat");
//    pet2.set_color("dark");

//    auto child=person.children(0);
//    child.set_name("cxq");
//    child.set_id(19);
//    child.add_favorite("basketball");
//    child.add_favorite("fish");
//    child.set_day(cxq_pkg::people_weekday_sunday);
//    auto ptrc = person.msg();
//    ptrc.set_age(30);
//    ptrc.set_address("bj");
//
//    auto petc = person.pet(0);
//    petc.set_name("dog");
//    petc.set_color("yellow");
//
//    auto petc2 = person.pet(1);
//    petc2.set_name("cat");
//    petc2.set_color("dark");


    // Create a json_string from msg. [pb to json]
    google::protobuf::util::JsonPrintOptions options;
//    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    MessageToJsonString(person, &json_string, options);

    // Print json_string.
    std::cout << json_string << std::endl;

}


int main(int argc, char **argv) {
    pb2json3();
    return 0;
}