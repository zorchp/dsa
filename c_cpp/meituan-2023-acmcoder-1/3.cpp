#include <bits/stdc++.h>
using namespace std;
// 没通过的烂代码

int main() {
    int m, n, s, a, i{};
    cin >> n >> m >> s;
    vector<int> arr(n);
    while (i < n) cin >> a, arr[i++] = a;
    // for (auto aa : arr) cout << aa << endl;
    // int ans{};
    vector<int> dp(n); // 前j个水果的最小花费
    dp[0] = arr[0] + s;
    int mn = arr[0], mx = arr[0], grp{1};
    auto f = [&](int k, int mn, int mx) { return k * (mn + mx) / 2 + s; };

    for (int i{1}; i < n; ++i) {
        if (grp == m) {       // 只能新开一组
            mx = mn = arr[i]; // 重新记录最值
            dp[i] = dp[i - 1] + arr[i] + s;
            grp = 1;
        } else { // 可以选择并入还是独立成组
            // 并入, 记录最值
            if (arr[i] < mn) {
                if (mx + (grp + 1) * arr[i] < grp * mn) {
                    dp[i] = dp[i - 1] - f(grp, mn, mx) + f(grp + 1, arr[i], mx);
                    mn = arr[i];
                    grp++;
                }
            } else if (arr[i] > mx && mn + arr[i] * (grp + 1) < grp * mx) {
                dp[i] = dp[i - 1] - f(grp, mn, mx) + f(grp + 1, mn, arr[i]);
                mx = arr[i];
                grp++;
            } else { // arr[i]in[mn,mx]
                if ((mn + mx) / 2 > s + arr[i])
                    dp[i] = dp[i - 1] + s + arr[i];
                else // 合并更小
                    dp[i] = dp[i - 1] + (mn + mx) / 2, grp++;
            }
        }
    }
    cout << dp[n-1] << endl;
}