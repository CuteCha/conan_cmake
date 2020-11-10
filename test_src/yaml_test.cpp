#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

void parse() {
    YAML::Node node = YAML::Load("[22,3,4,4]");
    std::cout << node[0] << std::endl;

    YAML::Node config = YAML::LoadFile("../../conf/config.yaml");

    std::cout << config["on_rtp"] << std::endl;
    std::cout << config["on_rtp"].as<bool>() << std::endl;

    for (YAML::const_iterator it = config["skills"].begin(); it != config["skills"].end(); ++it) {
        std::cout << it->first.as<std::string>() << ":" << it->second.as<int>() << std::endl;
    }

    YAML::Node node2 = YAML::Load("arr: 1");
    std::cout << "arr: " << node["arr"] << std::endl;
    std::cout << "yaml" << std::endl;
}

void write_yaml() {
    YAML::Node config;
    std::ofstream fout("../../data/test_config.yaml");
    config["score"] = 99;

    fout << config;
    fout.close();
    std::cout << "done" << std::endl;

}

int main() {
    parse();
    write_yaml();

    return 0;
}

