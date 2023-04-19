#include <iostream>
using namespace std;

int mul1(int a, int b) {
    int ans{};
    bool sgn = (a > 0) ^ (b > 0);
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        if (b & 1) ans += a;
        a += a;
        b >>= 1;
    }
    return sgn ? -ans : ans;
}

int mul(int a, int b) {
    if (!a || !b) return 0;
    bool sgn = (a > 0) ^ (b > 0);
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    function<int(int, int)> f = [&](int a, int b) {
        if (b == 1) return a;
        int y{f(a, b >> 1)};
        return b % 2 ? y + a + y : y + y;
    };
    return sgn ? -f(a, b) : f(a, b);
}

void t1() {
    cout << mul(12, 23) << " " << 12 * 23 << endl;
    cout << mul(-12, -23) << " " << -12 * -23 << endl;
    cout << mul(12, -23) << " " << 12 * -23 << endl;
    cout << mul(-12, 23) << " " << -12 * 23 << endl;
    cout << mul(-12, 0) << " " << -12 * 0 << endl;
    // 276 276
    // 276 276
    // -276 -276
    // -276 -276
    // 0 0
}

void t2() {
    cout << mul(5, 3) << " " << 5 * 3 << endl; //
    cout << mul(3, 5) << " " << 5 * 3 << endl; //
}


int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
