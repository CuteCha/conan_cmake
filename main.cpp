#include <iostream>
#include "png.h"
#include "zlib.h"
#include <gflags/gflags.h>
#include "glog/logging.h"

DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english,french,german", "list of languages to offer in the 'lang' menu");

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

void output_vec(const std::vector<std::string> &vec) {
    std::cout << "[";
    for (auto &item: vec) {
        std::cout << item << ", ";
    }
    std::cout << "]" << std::endl;

}

void test_split() {
    std::vector<std::string> vec;
    std::string s = "english,french,german";
    SplitString(s, vec, ",");
    output_vec(vec);
}

int main(int argc, char **argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = "./logs"; //指定glog输出文件路径（输出格式为 "<program name>.<hostname>.<user name>.log.<severity level>.<date>.<time>.<pid>"）
    google::SetLogDestination(google::INFO, "./logs/info_"); //第一个参数为日志级别，第二个参数表示输出目录及日志文件名前缀。
    FLAGS_alsologtostderr = true; // 日志输出到stderr（终端屏幕），同时输出到日志文件。 FLAGS_logtostderr = true 日志输出到stderr，不输出到日志文件。
    FLAGS_colorlogtostderr = true; //输出彩色日志到stderr
    FLAGS_minloglevel = 0; //将大于等于该级别的日志同时输出到stderr和指定文件。日志级别 INFO, WARNING, ERROR, FATAL 的值分别为0、1、2、3。

    LOG(INFO) << "info message...";
    LOG(WARNING) << "warning message...";
    LOG(ERROR) << "error message...";
    VLOG(10)<<"vlog info 10";
    //LOG(FATAL) << "fatal message..."; //打印完信息后程序终止报错
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Compiled with libpng " << PNG_LIBPNG_VER_STRING << " using libpng " << png_libpng_ver << std::endl;
    std::cout << "Compiled with zlib " << ZLIB_VERSION << " using zlib " << zlib_version << std::endl;
    std::cout << FLAGS_big_menu << std::endl;
    std::cout << FLAGS_languages << std::endl;
    test_split();
    google::ShutdownGoogleLogging();
    return 0;
}
