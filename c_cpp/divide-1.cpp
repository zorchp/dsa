#include <climits>
#include <cstdio>

class Solution {
    constexpr static int LMT = INT_MIN >> 1; // half
public:
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1)
            return INT_MAX; // Overflow
        bool isNeg = (a > 0) ^ (b > 0);
        if (a > 0)
            a = -a;
        if (b > 0)
            b = -b; // map to [INT_MIN, 0]
        int ans{}, c, d;
        while (a <= b) {
            c = b, d = -1;
            while (c >= LMT && c >= a - c)
                c += c, d += d;
            ans += d, a -= c;
        }
        return isNeg ? ans : -ans;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    printf("ans=%d\n", s.divide(7, 2));
    return 0;
}
