#include <iostream>
#include <unordered_set>
#include <vector>
#include "../include/Triangle.h"
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

void outputMap2() {
    std::map<std::string, int> map = {

            {"exposure_uv_1d",           1},
            {"exposure_uv_3d",           2},
            {"exposure_uv_7d",           3},
            {"exposure_uv_15d",          4},
            {"exposure_uv_30d",          5},

            {"watch_uv_1d",              6},
            {"watch_uv_3d",              7},
            {"watch_uv_7d",              8},
            {"watch_uv_15d",             9},
            {"watch_uv_30d",             10},

            {"watch_time_1d",            11},
            {"watch_time_3d",            12},
            {"watch_time_7d",            13},
            {"watch_time_15d",           14},
            {"watch_time_30d",           15},

            {"effective_watch_uv_1d",    16},
            {"effective_watch_uv_3d",    17},
            {"effective_watch_uv_7d",    18},
            {"effective_watch_uv_15d",   19},
            {"effective_watch_uv_30d",   20},

            {"effective_watch_time_1d",  21},
            {"effective_watch_time_3d",  22},
            {"effective_watch_time_7d",  23},
            {"effective_watch_time_15d", 24},
            {"effective_watch_time_30d", 25},

            {"heart_cnt_1d",             26},
            {"heart_cnt_3d",             27},
            {"heart_cnt_7d",             28},
            {"heart_cnt_15d",            29},
            {"heart_cnt_30d",            30},

            {"heart_uv_1d",              31},
            {"heart_uv_3d",              32},
            {"heart_uv_7d",              33},
            {"heart_uv_15d",             34},
            {"heart_uv_30d",             35},

            {"bullet_cnt_1d",            36},
            {"bullet_cnt_3d",            37},
            {"bullet_cnt_7d",            38},
            {"bullet_cnt_15d",           39},
            {"bullet_cnt_30d",           40},

            {"bullet_uv_1d",             41},
            {"bullet_uv_3d",             42},
            {"bullet_uv_7d",             43},
            {"bullet_uv_15d",            44},
            {"bullet_uv_30d",            45},

            {"msg_cnt_1d",               46},
            {"msg_cnt_3d",               47},
            {"msg_cnt_7d",               48},
            {"msg_cnt_15d",              49},
            {"msg_cnt_30d",              50},

            {"msg_uv_1d",                51},
            {"msg_uv_3d",                52},
            {"msg_uv_7d",                53},
            {"msg_uv_15d",               54},
            {"msg_uv_30d",               55},

            {"follow_uv_1d",             56},
            {"follow_uv_3d",             57},
            {"follow_uv_7d",             58},
            {"follow_uv_15d",            59},
            {"follow_uv_30d",            60},

            {"share_cnt_1d",             61},
            {"share_cnt_3d",             62},
            {"share_cnt_7d",             63},
            {"share_cnt_15d",            64},
            {"share_cnt_30d",            65},

            {"share_uv_1d",              66},
            {"share_uv_3d",              67},
            {"share_uv_7d",              68},
            {"share_uv_15d",             69},
            {"share_uv_30d",             70},

            {"gift_total_1d",            71},
            {"gift_total_3d",            72},
            {"gift_total_7d",            73},
            {"gift_total_15d",           74},
            {"gift_total_30d",           75},

            {"gift_uv_1d",               76},
            {"gift_uv_3d",               77},
            {"gift_uv_7d",               78},
            {"gift_uv_15d",              79},
            {"gift_uv_30d",              80},

            {"click_rate_1d",            81},
            {"click_rate_3d",            82},
            {"click_rate_7d",            83},
            {"click_rate_15d",           84},
            {"click_rate_30d",           85},

            {"avg_watch_time_1d",        86},
            {"avg_watch_time_3d",        87},
            {"avg_watch_time_7d",        88},
            {"avg_watch_time_15d",       89},
            {"avg_watch_time_30d",       90},

            {"effective_watch_rate_1d",  91},
            {"effective_watch_rate_3d",  92},
            {"effective_watch_rate_7d",  93},
            {"effective_watch_rate_15d", 94},
            {"effective_watch_rate_30d", 95},

            {"heart_rate_1d",            96},
            {"heart_rate_3d",            97},
            {"heart_rate_7d",            98},
            {"heart_rate_15d",           99},
            {"heart_rate_30d",           100},

            {"bullet_rate_1d",           101},
            {"bullet_rate_3d",           102},
            {"bullet_rate_7d",           103},
            {"bullet_rate_15d",          104},
            {"bullet_rate_30d",          105},

            {"msg_rate_1d",              106},
            {"msg_rate_3d",              107},
            {"msg_rate_7d",              108},
            {"msg_rate_15d",             109},
            {"msg_rate_30d",             110},

            {"follow_rate_1d",           111},
            {"follow_rate_3d",           112},
            {"follow_rate_7d",           113},
            {"follow_rate_15d",          114},
            {"follow_rate_30d",          115},

            {"share_rate_1d",            116},
            {"share_rate_3d",            117},
            {"share_rate_7d",            118},
            {"share_rate_15d",           119},
            {"share_rate_30d",           120},

            {"gift_rate_1d",             121},
            {"gift_rate_3d",             122},
            {"gift_rate_7d",             123},
            {"gift_rate_15d",            124},
            {"gift_rate_30d",            125}
    };


    std::cout << "---------------map.size=" << map.size() << std::endl;

    for (auto &item: map) {
        std::cout << "k=" << item.first << ", v=" << item.second << std::endl;
    }
}

void outputMap3() {
    std::map<std::string, int> map = {
            {"real_num",   1},
            {"fake_num",   2},
            {"bit_rate",   3},
            {"fps",        4},
            {"enter_cnt",  5},
            {"leave_cnt",  6},
            {"bean_cnt",   7},
            {"bean_uv",    8},
            {"fans_cnt",   9},
            {"share_cnt",  10},
            {"heart_cnt",  11},
            {"msg_cnt",    12},
            {"is_qianyue", 13},
            {"fans_num",   14}
    };


    std::cout << "---------------map.size=" << map.size() << std::endl;

    int i = 1;
    for (auto &item: map) {
        std::cout << i << ": k=" << item.first << ", v=" << item.second << std::endl;
        i++;
    }
}

void outputMap202() {
    std::map<std::string, int> map = {
            {"bean_uv_1d",        1},
            {"bean_uv_3d",        2},
            {"bean_uv_7d",        3},
            {"bean_uv_30d",       4},
            {"bean_cnt_1d",       5},
            {"bean_cnt_3d",       6},
            {"bean_cnt_7d",       7},
            {"bean_cnt_30d",      8},
            {"follow_uv_1d",      9},
            {"follow_uv_3d",      10},
            {"follow_uv_7d",      11},
            {"follow_uv_30d",     12},
            {"unfollow_uv_1d",    13},
            {"unfollow_uv_3d",    14},
            {"unfollow_uv_7d",    15},
            {"unfollow_uv_30d",   16},
            {"stay_time_1d",      17},
            {"stay_time_3d",      18},
            {"stay_time_7d",      19},
            {"stay_time_30d",     20},
            {"eff_stay_time_1d",  21},
            {"eff_stay_time_3d",  22},
            {"eff_stay_time_7d",  23},
            {"eff_stay_time_30d", 24},
            {"enter_uv_1d",       25},
            {"enter_uv_3d",       26},
            {"enter_uv_7d",       27},
            {"enter_uv_30d",      28}
    };


    std::cout << "---------------map.size=" << map.size() << std::endl;

    int i = 1;
    for (auto &item: map) {
        std::cout << i << ": k=" << item.first << ", v=" << item.second << std::endl;
        i++;
    }
}

void outputMap303() {
    std::map<std::string, int> map = {
            {"exposure_time_1d", 1},
            {"exposure_time_3d", 2},
            {"exposure_time_7d", 3},
            {"exposure_time_15d", 4},
            {"exposure_time_30d", 5},

            {"enter_time_1d", 6},
            {"enter_time_3d", 7},
            {"enter_time_7d", 8},
            {"enter_time_15d", 9},
            {"enter_time_30d", 10},

            {"watch_time_1d", 11},
            {"watch_time_3d", 12},
            {"watch_time_7d", 13},
            {"watch_time_15d", 14},
            {"watch_time_30d", 15},

            {"effective_enter_time_1d", 16},
            {"effective_enter_time_3d", 17},
            {"effective_enter_time_7d", 18},
            {"effective_enter_time_15d", 19},
            {"effective_enter_time_30d", 20},

            {"effective_watch_time_1d", 21},
            {"effective_watch_time_3d", 22},
            {"effective_watch_time_7d", 23},
            {"effective_watch_time_15d", 24},
            {"effective_watch_time_30d", 25},

            {"heart_cnt_1d", 26},
            {"heart_cnt_3d", 27},
            {"heart_cnt_7d", 28},
            {"heart_cnt_15d", 29},
            {"heart_cnt_30d", 30},

            {"bullet_cnt_1d", 31},
            {"bullet_cnt_3d", 32},
            {"bullet_cnt_7d", 33},
            {"bullet_cnt_15d", 34},
            {"bullet_cnt_30d", 35},

            {"msg_cnt_1d", 36},
            {"msg_cnt_3d", 37},
            {"msg_cnt_7d", 38},
            {"msg_cnt_15d", 39},
            {"msg_cnt_30d", 40},

            {"follow_1d", 41},
            {"follow_3d", 42},
            {"follow_7d", 43},
            {"follow_15d", 44},
            {"follow_30d", 45},

            {"share_cnt_1d", 46},
            {"share_cnt_3d", 47},
            {"share_cnt_7d", 48},
            {"share_cnt_15d", 49},
            {"share_cnt_30d", 50},

            {"gift_total_1d", 51},
            {"gift_total_3d", 52},
            {"gift_total_7d", 53},
            {"gift_total_15d", 54},
            {"gift_total_30d", 55},

            {"gift_time_1d", 56},
            {"gift_time_3d", 57},
            {"gift_time_7d", 58},
            {"gift_time_15d", 59},
            {"gift_time_30d", 60},

            {"gift_combo_1d", 61},
            {"gift_combo_3d", 62},
            {"gift_combo_7d", 63},
            {"gift_combo_15d", 64},
            {"gift_combo_30d", 65},


            {"click_rate_1d", 66},
            {"click_rate_3d", 67},
            {"click_rate_7d", 68},
            {"click_rate_15d", 69},
            {"click_rate_30d", 70},

            {"avg_watch_time_1d", 71},
            {"avg_watch_time_3d", 72},
            {"avg_watch_time_7d", 73},
            {"avg_watch_time_15d", 74},
            {"avg_watch_time_30d", 75},

            {"effect_enter_rate_1d", 76},
            {"effect_enter_rate_3d", 77},
            {"effect_enter_rate_7d", 78},
            {"effect_enter_rate_15d", 79},
            {"effect_enter_rate_30d", 80},

            {"avg_heart_cnt_1d", 81},
            {"avg_heart_cnt_3d", 82},
            {"avg_heart_cnt_7d", 83},
            {"avg_heart_cnt_15d", 84},
            {"avg_heart_cnt_30d", 85},

            {"avg_bullet_cnt_1d", 86},
            {"avg_bullet_cnt_3d", 87},
            {"avg_bullet_cnt_7d", 88},
            {"avg_bullet_cnt_15d", 89},
            {"avg_bullet_cnt_30d", 90},

            {"avg_msg_cnt_1d", 91},
            {"avg_msg_cnt_3d", 92},
            {"avg_msg_cnt_7d", 93},
            {"avg_msg_cnt_15d", 94},
            {"avg_msg_cnt_30d", 95},

            {"avg_follow_cnt_1d", 96},
            {"avg_follow_cnt_3d", 97},
            {"avg_follow_cnt_7d", 98},
            {"avg_follow_cnt_15d", 99},
            {"avg_follow_cnt_30d", 100},

            {"avg_share_cnt_1d", 101},
            {"avg_share_cnt_3d", 102},
            {"avg_share_cnt_7d", 103},
            {"avg_share_cnt_15d", 104},
            {"avg_share_cnt_30d", 105},

            {"avg_gift_cnt_1d", 106},
            {"avg_gift_cnt_3d", 107},
            {"avg_gift_cnt_7d", 108},
            {"avg_gift_cnt_15d", 109},
            {"avg_gift_cnt_30d", 110},

            {"avg_gift_time_1d", 111},
            {"avg_gift_time_3d", 112},
            {"avg_gift_time_7d", 113},
            {"avg_gift_time_15d", 114},
            {"avg_gift_time_30d", 115}
    };


    std::cout << "---------------map.size=" << map.size() << std::endl;

    int i = 1;
    for (auto &item: map) {
        std::cout << i << ": k=" << item.first << ", v=" << item.second << std::endl;
        i++;
    }
}

void outputMap203() {
    std::map<std::string, int> map = {
            {"exposure_uv_1d", 1},
            {"exposure_uv_3d", 1},
            {"exposure_uv_7d", 1},
            {"exposure_uv_15d", 1},
            {"exposure_uv_30d", 1},


            {"watch_uv_1d", 1},
            {"watch_uv_3d", 1},
            {"watch_uv_7d", 1},
            {"watch_uv_15d", 1},
            {"watch_uv_30d", 1},



            {"watch_time_1d", 1},
            {"watch_time_3d", 1},
            {"watch_time_7d", 1},
            {"watch_time_15d", 1},
            {"watch_time_30d", 1},

            {"effective_watch_uv_1d", 1},
            {"effective_watch_uv_3d", 1},
            {"effective_watch_uv_7d", 1},
            {"effective_watch_uv_15d", 1},
            {"effective_watch_uv_30d", 1},

            {"effective_watch_time_1d", 1},
            {"effective_watch_time_3d", 1},
            {"effective_watch_time_7d", 1},
            {"effective_watch_time_15d", 1},
            {"effective_watch_time_30d", 1},

            {"heart_cnt_1d", 1},
            {"heart_cnt_3d", 1},
            {"heart_cnt_7d", 1},
            {"heart_cnt_15d", 1},
            {"heart_cnt_30d", 1},

            {"heart_uv_1d", 1},
            {"heart_uv_3d", 1},
            {"heart_uv_7d", 1},
            {"heart_uv_15d", 1},
            {"heart_uv_30d", 1},

            {"bullet_cnt_1d", 1},
            {"bullet_cnt_3d", 1},
            {"bullet_cnt_7d", 1},
            {"bullet_cnt_15d", 1},
            {"bullet_cnt_30d", 1},

            {"bullet_uv_1d", 1},
            {"bullet_uv_3d", 1},
            {"bullet_uv_7d", 1},
            {"bullet_uv_15d", 1},
            {"bullet_uv_30d", 1},

            {"msg_cnt_1d", 1},
            {"msg_cnt_3d", 1},
            {"msg_cnt_7d", 1},
            {"msg_cnt_15d", 1},
            {"msg_cnt_30d", 1},

            {"msg_uv_1d", 1},
            {"msg_uv_3d", 1},
            {"msg_uv_7d", 1},
            {"msg_uv_15d", 1},
            {"msg_uv_30d", 1},

            {"follow_uv_1d", 1},
            {"follow_uv_3d", 1},
            {"follow_uv_7d", 1},
            {"follow_uv_15d", 1},
            {"follow_uv_30d", 1},

            {"share_cnt_1d", 1},
            {"share_cnt_3d", 1},
            {"share_cnt_7d", 1},
            {"share_cnt_15d", 1},
            {"share_cnt_30d", 1},

            {"share_uv_1d", 1},
            {"share_uv_3d", 1},
            {"share_uv_7d", 1},
            {"share_uv_15d", 1},
            {"share_uv_30d", 1},

            {"gift_total_1d", 1},
            {"gift_total_3d", 1},
            {"gift_total_7d", 1},
            {"gift_total_15d", 1},
            {"gift_total_30d", 1},

            {"gift_uv_1d", 1},
            {"gift_uv_3d", 1},
            {"gift_uv_7d", 1},
            {"gift_uv_15d", 1},
            {"gift_uv_30d", 1},

            {"click_rate_1d", 1},
            {"click_rate_3d", 1},
            {"click_rate_7d", 1},
            {"click_rate_15d", 1},
            {"click_rate_30d", 1},

            {"avg_watch_time_1d", 1},
            {"avg_watch_time_3d", 1},
            {"avg_watch_time_7d", 1},
            {"avg_watch_time_15d", 1},
            {"avg_watch_time_30d", 1},

            {"effective_watch_rate_1d", 1},
            {"effective_watch_rate_3d", 1},
            {"effective_watch_rate_7d", 1},
            {"effective_watch_rate_15d", 1},
            {"effective_watch_rate_30d", 1},

            {"heart_rate_1d", 1},
            {"heart_rate_3d", 1},
            {"heart_rate_7d", 1},
            {"heart_rate_15d", 1},
            {"heart_rate_30d", 1},

            {"bullet_rate_1d", 1},
            {"bullet_rate_3d", 1},
            {"bullet_rate_7d", 1},
            {"bullet_rate_15d", 1},
            {"bullet_rate_30d", 1},

            {"msg_rate_1d", 1},
            {"msg_rate_3d", 1},
            {"msg_rate_7d", 1},
            {"msg_rate_15d", 1},
            {"msg_rate_30d", 1},

            {"follow_rate_1d", 1},
            {"follow_rate_3d", 1},
            {"follow_rate_7d", 1},
            {"follow_rate_15d", 1},
            {"follow_rate_30d", 1},

            {"share_rate_1d", 1},
            {"share_rate_3d", 1},
            {"share_rate_7d", 1},
            {"share_rate_15d", 1},
            {"share_rate_30d", 1},

            {"gift_rate_1d", 1},
            {"gift_rate_3d", 1},
            {"gift_rate_7d", 1},
            {"gift_rate_15d", 1},
            {"gift_rate_30d", 1}
    };


    std::cout << "---------------map.size=" << map.size() << std::endl;

    int i = 1;
    for (auto &item: map) {
        std::cout << i << ": k=" << item.first << ", v=" << item.second << std::endl;
        i++;
    }
}

void SplitString(const std::string &s, std::vector<std::string> &v, const std::string &c) {
    std::string::size_type pos1, pos2;
    std::string::size_type c_size = c.size();
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        v.emplace_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c_size;
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

void test1() {
    std::unordered_set<std::string> set;
    std::vector<std::string> vec;
    std::string s = "";//"english,french,german";
    SplitString(s, vec, ",");
    for (auto &item: vec) {
        std::cout << item << std::endl;
        set.insert(item);
    }
    std::cout << "---------------" << std::endl;
    for (auto &item: set) {
        std::cout << item << std::endl;
    }

}

int main(int argc, char **argv) {
    std::cout << "[Debug]" << std::endl;
    outputMap203();

    return 0;
}
