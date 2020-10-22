#include<iostream>
#include<thread>
#include <chrono>
#include <queue>
#include "../include/threadpool.h"


void proc(int a) {
    std::cout << "我是子线程,传入参数为" << a << std::endl;
    std::cout << "子线程中显示子线程id为" << std::this_thread::get_id() << std::endl;
    std::cout << "子线程 done" << std::endl;
}

void test1() {
    std::cout << "我是主线程" << std::endl;
    int a = 9;
    std::thread th2(proc, a);//第一个参数为函数名，第二个参数为该函数的第一个参数，如果该函数接收多个参数就依次写在后面。此时线程开始执行。
    std::cout << "主线程中显示子线程id为" << th2.get_id() << std::endl;
    th2.join(); //此时主线程被阻塞直至子线程执行结束。
    std::cout << "主线程 done" << std::endl;
}

void test2() {
    std::cout << "我是主线程" << std::endl;

    std::thread th1(proc, 1);
    std::cout << "1主线程中显示子线程id为" << th1.get_id() << std::endl;
    std::thread th2(proc, 2);
    std::cout << "2主线程中显示子线程id为" << th2.get_id() << std::endl;
    std::thread th3(proc, 3);
    std::cout << "3主线程中显示子线程id为" << th3.get_id() << std::endl;
    th1.join();
    th2.join();
    th3.join();


    std::cout << "主线程 done" << std::endl;
}

void test3() {
    ThreadPool pool(4);
    std::vector<std::future<int> > results;

    for (int i = 0; i < 8; ++i) {
        results.emplace_back(
                pool.enqueue([i] {
                    std::cout << "hello " << i << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "world " << i << std::endl;
                    return i * i;
                })
        );
    }

    std::cout << "---------------" << std::endl;
    for (auto &&result: results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;
}

void test4(){
    std::thread t([] {
        std::cout << "Hello World from lambda thread." << std::endl;
    });

    t.join();
}

int main() {
    test4();
    return 0;
}