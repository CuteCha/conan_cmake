#include <fstream>
#include <iostream>

#include "proto/test.pb.h"
#include "proto/people.pb.h"
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <fcntl.h>


void print_msg(pkg::helloworld &msg) {
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

void save_config(std::string &file_name, std::string &contect) {
    std::ofstream fout;
    fout.open(file_name.c_str(), std::ios::out | std::ios_base::ate);

    if (!fout.is_open()) {
        fprintf(stderr, "open config file fail\n");
        exit(-1);
    }

    fout << contect << std::endl;
    fout.flush();
    fout.close();
}

void load_config(std::string &file_name, pkg::helloworld &config) {
    int fd = open(file_name.c_str(), O_RDONLY);

    if (fd < 0) {
        printf("open config file failure:%s \n", strerror(errno));
        exit(-1);
    }

    google::protobuf::io::FileInputStream fileInput(fd);
    fileInput.SetCloseOnDelete(true);
    google::protobuf::TextFormat::Parse(&fileInput, &config);
}

void pb2config() {
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

    std::string text;
    google::protobuf::TextFormat::PrintToString(msg, &text);

    std::string file_name = "../../conf/test.conf";
    save_config(file_name, text);
    std::cout << "done" << std::endl;

}

void config2pb() {
    std::string file_name = "../../conf/test.conf";
    pkg::helloworld msg;
    load_config(file_name, msg);
    print_msg(msg);
    std::cout << "done" << std::endl;
}

int main(int argc, char **argv) {
//    pb2config();
    config2pb();
    return 0;
}

