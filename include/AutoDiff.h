

#ifndef CONAN_CMAKE_AUTODIFF_H
#define CONAN_CMAKE_AUTODIFF_H
namespace AD {
    class AutoDiff {
    public:
        double val;  // value of the variable
        double d_val;  // derivative of the variable
        AutoDiff(double v = 0, double d = 0);

        AutoDiff operator+(const AutoDiff &x);

        AutoDiff operator-(const AutoDiff &x);

        AutoDiff operator*(const AutoDiff &x);

        friend AutoDiff sin(const AutoDiff &x);

        friend AutoDiff cos(const AutoDiff &x);
    };
}

#endif //CONAN_CMAKE_AUTODIFF_H

