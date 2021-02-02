#include "../include/Car.h"
#include <iostream>

void Car::copy_name(const char *name) {
    if (name == NULL) return;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}

Car::Car(double price, const char *name) : m_price(price) {
    std::cout << "Car::Car(double price, const char *name)" << std::endl;
    copy_name(name);
}

Car::Car(const Car &car) : m_price(car.m_price) {
    std::cout << "Car::Car(const Car &car)" << std::endl;
    copy_name(car.m_name);
}

Car::~Car() {
    std::cout << "Car::~Car()" << std::endl;
    if (m_name == NULL) return;
    delete[] m_name;
    m_name == NULL;
}

void Car::display() {
    std::cout << "m_name=" << m_name << ", price=" << m_price
              << "name address:"<< &m_name << std::endl;
}