#include <fstream>
#include <iostream>

#include "proto/test.pb.h"

using namespace std;

int main(void) {
  zcy::helloworld msg1;

  // 对于string变量的使用方法
  msg1.set_student_name("cxq");

  // 对于repeated int32的变量的使用方法
  msg1.add_school_id(1);
  msg1.add_school_id(2);
  msg1.add_school_id(3);
  msg1.add_school_id(4);
  msg1.add_school_id(5);

  // 对于枚举变量的使用方法
  msg1.set_day(zcy::helloworld_weekday_monday);

  // 对于sub message的使用方法，使用指针的方式来对变量进行修改
  auto ptr = msg1.mutable_submess();
  ptr->set_age(36);
  ptr->set_name("james");

  // Write the new date back to disk.
  fstream output("./xxx_out", ios::out | ios::trunc | ios::binary);

  if (!msg1.SerializeToOstream(&output)) {
    cerr << "Failed to write msg." << endl;
    return -1;
  }
  return 0;
}