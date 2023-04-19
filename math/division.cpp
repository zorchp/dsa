#include <iostream>
using namespace std;


int find_nice(int reminder, int divisor) {
    int l{}, r{9}, mid{};
    while (l <= r) {
        mid = (l + r) >> 1;
        if (divisor * mid <= reminder)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l - 1;
}

int divide(int dividend, int divisor) {
    int flg1{}, flg2{};
    long dvd = dividend, dvs = divisor;
    if (dvd < 0) {
        dvd = -dvd;
        flg1 = 1;
    }
    if (dvs < 0) {
        dvs = -dvs;
        flg2 = 1;
    }
    long l{}, r = dvd, mid{};
    while (l <= r) {
        mid = (l + r) >> 1;
        if (dvs * mid <= dvd)
            l = mid + 1;
        else
            r = mid - 1;
    }
    long ans = (flg1 != flg2 ? 1 - l : l - 1);
    return ans > INT32_MAX || ans < INT32_MIN ? INT32_MAX : ans;
}
void t1() {
    cout << find_nice(10, 3) << std::endl;
    cout << find_nice(10, 4) << std::endl;
    cout << find_nice(10, 5) << std::endl;
}

void t2() {
    // cout << INT32_MIN << endl;
    // cout << INT32_MAX << endl;
    // cout << divide(-7, -3) << endl;
    cout << divide(-1010369383, -2147483648) << endl;
    // cout << divide(-2147483648, -1) << endl;
}

class Solution {
    int LIMIT{INT_MIN >> 1};

public:
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1) return INT_MAX;
        bool isNeg = (a > 0) ^ (b > 0);
        if (a > 0) a = -a;
        if (b > 0) b = -b;
        int ans{};
        while (a <= b) {
            int c{b}, d{-1};
            while (c >= LIMIT && d >= LIMIT && c >= a - c) c += c, d += d;
            a -= c;
            ans += d;
        }
        return isNeg ? ans : -ans;
    }
};


int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}