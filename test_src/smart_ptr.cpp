#include <memory>
#include <iostream>

void test1() {
    std::string s("hello world");
    auto s2 = new std::string("hello world");
    std::string s3 = "hello world";
    std::cout << s << std::endl;
    std::cout << *s2 << std::endl;
    std::cout << s3 << std::endl;

    std::unique_ptr<std::string> pu1(new std::string("hello world"));
    std::unique_ptr<std::string> pu2;
    //pu2 = pu1;                                      // #1 不允许
    std::unique_ptr<std::string> pu3;
    pu3 = std::unique_ptr<std::string>(new std::string("You"));
    std::cout << *pu3 << std::endl;
}

void test2() {
    int *p1 = new int(1);
    int *p2 = p1;
    int *p3 = p2;

    delete p1;
    std::cout << *p2 << std::endl;
}

void test3() {
    std::unique_ptr<int> up1(new int(10)); // 不能复制的unique_ptr
    // unique_ptr<int> up2 = up1; // 这样是错的
    std::cout << *up1 << std::endl;

    std::unique_ptr<int> up3 = std::move(up1); // 现在up3是数据唯一的unique_ptr智能指针
    std::cout << *up3 << std::endl;
    // cout<<*up1<<endl; // 运行时错误

    up3.reset(); // 显式释放内存
    up1.reset(); // 即使up1没有拥有任何内存，但是这样调用也没有问题
    // cout<<*up3<<endl; // 已经释放掉up3了，这样会运行时错误

    std::shared_ptr<int> sp1(new int(20));
    std::shared_ptr<int> sp2 = sp1; // 这是完全可以的，增加引用计数

    std::cout << *sp1 << std::endl;
    std::cout << *sp2 << std::endl;

    std::cout << sp2.use_count() << std::endl;
    sp1.reset(); // 减少引用计数
    std::cout << *sp2 << std::endl;
    std::cout << sp2.use_count() << std::endl;
}

void test4() {
    std::shared_ptr<int> fsPtr(new int(5));
    std::weak_ptr<int> fwPtr = fsPtr;

    //weak_ptr不会改变shared_ptr，但是会和shared_ptr的引用保持一致
    std::cout << "fsPtr use_count:" << fsPtr.use_count() << " fwPtr use_count:" << fwPtr.use_count() << std::endl;

    //fwPtr.lock()后会该变shared_ptr的引用计数(+1)
    std::shared_ptr<int> fsPtr2 = fwPtr.lock();
    std::cout << "fsPtr use_count:" << fsPtr.use_count() << " fwPtr use_count:" << fwPtr.use_count() << std::endl;

    //编译报错，weak_ptr没有重载*，->操作符，因此不可直接通过weak_ptr使用对象,只能通过lock()使用shared_ptr来操作
    std::cout << " number is " << *fsPtr2 << std::endl;

    fsPtr.reset();
    if (fwPtr.expired()) {
        std::cout << "shared_ptr object has been destory" << std::endl;
    }


    std::shared_ptr<int> fsPtr3 = fwPtr.lock();                //fsPtr3为NULL
    std::cout << " number is " << *fsPtr3 << std::endl; //运行时中断
}

int main() {
    test4();

    return 0;
}