#include <fstream>
#include <iostream>

#include "proto/test.pb.h"

using namespace std;

void ListMsg(const zcy::helloworld &msg) {
  // 对于string变量的使用方法
  cout << msg.student_name() << endl;

  // 对于repeated int32变量的使用方法
  for (int i = 0; i < msg.school_id_size(); ++i) {
    cout << msg.school_id(i) << endl;
  }

  for (auto item : msg.school_id()) {
    cout << item << endl;
  }

  // 对于子message变量的使用方法
  cout << msg.submess().name() << endl;
  cout << msg.submess().age() << endl;

  // 对于枚举类变量的使用方法
  cout << msg.day() << endl;
}

int main(int argc, char *argv[]) {
  zcy::helloworld msg1;

  {
    fstream input("./xxx_out", ios::in | ios::binary);
    if (!msg1.ParseFromIstream(&input)) {
      cerr << "Failed to read data." << endl;
      return -1;
    }
  }

  ListMsg(msg1);
}
