#include "../include/AutoDiff.h"
#include  <cmath>


namespace AD {
    AutoDiff::AutoDiff(double v, double d) {
        val = v;
        d_val = d;
    }

    AutoDiff AutoDiff::operator+(const AutoDiff &x) {
        AutoDiff y;
        y.val = val + x.val;
        y.d_val = d_val + x.d_val;

        return y;
    }

    AutoDiff AutoDiff::operator-(const AutoDiff &x) {
        AutoDiff y;
        y.val = val - x.val;
        y.d_val = d_val - x.d_val;

        return y;
    }

    AutoDiff AutoDiff::operator*(const AutoDiff &x) {
        AutoDiff y;
        y.val = val * x.val;
        y.d_val = d_val * x.val + val * x.d_val;

        return y;
    }

    AutoDiff sin(const AutoDiff &x) {
        AutoDiff y;
        y.val = std::sin(x.val);
        y.d_val = x.d_val * std::cos(x.val);

        return y;
    }

    AutoDiff cos(const AutoDiff &x) {
        AutoDiff y;
        y.val = std::cos(x.val);
        y.d_val = -x.d_val * std::sin(x.val);

        return y;
    }
}