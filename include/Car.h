
#ifndef CONAN_CMAKE_CAR_H
#define CONAN_CMAKE_CAR_H

class Car {
private:
    double m_price;
    char *m_name;

    void copy_name(const char *name);

public:
    Car(double price, const char *name);

    Car(const Car &car);

    ~Car();

    void display();
};

#endif //CONAN_CMAKE_CAR_H
