#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

class Solution {
public:
    double myPow(double x, int n) {
        function<double(double, int)> f = [&](double x, int n) {
            if (n == 0) return 1.;
            double y{f(x, n >> 1)};
            return n % 2 ? y * y * x : y * y;
        };
        if (n == 1) return x;
        long m = 1l * n;
        return n > 0 ? f(x, m) : 1 / f(x, -m);
    }
};

class Solution1 {
public:
    double myPow(double x, int n) {
        long m = 1l * n;
        bool isNeg{m < 0};
        m = isNeg ? -m : m;
        double ans{1}, y{x};
        while (m) ans *= (m & 1) ? y : 1, y *= y, m >>= 1;
        return isNeg ? 1 / ans : ans;
    }
};
int main(int argc, char const* argv[]) {
    Solution s;
    cout << s.myPow(1.2, 10) << endl;
    return 0;
}