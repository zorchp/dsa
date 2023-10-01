#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), a{}, b{1}, c{};
        for (int i{1}; i <= n; ++i) {
            a = 0;
            if (s[i - 1] != '0')
                a += b;
            if (i > 1 && s[i - 2] != '0' && stoi(s.substr(i - 2, 2)) <= 26)
                a += c;
            c = b, b = a;
        }
        return a;
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
        int n = s.size(), dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i{1}; i <= n; ++i) {
            if (i > 1 && s[i - 2] != '0' && stoi(s.substr(i - 2, 2)) <= 26)
                dp[i] += dp[i - 2];

            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
        }
        return dp[n];
    }
};

class Solution1 {
public:
    int numDecodings(string s) {
        int n = s.size(), dp[n + 1];
        memset(dp, -1, sizeof(dp));
        function<int(int)> f = [&](int x) {
            if (x <= 0)
                return 1; // found
            int &res = dp[x];
            if (~res)
                return res; // exists
            res = 0;
            if (x > 1 && s[x - 2] != '0' && stoi(s.substr(x - 2, 2)) <= 26)
                res += f(x - 2);

            if (s[x - 1] != '0')
                res += f(x - 1);

            return res;
        };
        return f(n);
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    cout << s.numDecodings("226");
    return 0;
}
