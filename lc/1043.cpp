#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i{1}; i <= n; ++i)
            for (int j{i}, mx{}; i - j < k && j > 0; --j)
                mx = max(mx, arr[j - 1]),
                dp[i] = max(dp[i], dp[j - 1] + (i - j + 1) * mx);

        return dp[n];
    }
};

class Solution1 {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));
        function<int(int)> f = [&](int x) {
            if (x < 0)
                return 0;
            int &res = dp[x];
            if (~res)
                return res;
            for (int i{x}, mx{}; x - i < k && i >= 0; --i)
                mx = max(mx, arr[i]),
                res = max(res, f(i - 1) + (x - i + 1) * mx);
            return res;
        };
        return f(n - 1);
    }
};

int main(int argc, char *argv[]) {
    vector v = {1, 15, 7, 9, 2, 5, 10};
    Solution s;
    cout << s.maxSumAfterPartitioning(v, 3);

    return 0;
}
