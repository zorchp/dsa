#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}


class Solution1 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"s;
        int m = num1.size(), n = num2.size();
        int p{1}, N = m + n; // p: 乘完一步, 往前移动
        int ans[N], cur[N];
        memset(ans, 0, sizeof(ans));
        memset(cur, 0, sizeof(cur));
        for (int i{n - 1}; i >= 0; --i) {
            memset(cur, 0, sizeof(cur));
            int carry{}, y = num2[i] - '0', idx{N - p};
            for (int j{m - 1}; j >= 0; --j) {
                int prod{(num1[j] - '0') * y + carry};
                cur[idx--] = prod % 10, carry = prod / 10;
            }
            ++p;
            while (carry) cur[idx] = carry % 10, carry /= 10;
            // 合并入ans数组
            for (int i = N - 1, add{}; i >= 0; --i) {
                int tmp{ans[i] + cur[i] + add};
                ans[i] = tmp % 10;
                add = tmp / 10;
            }
        }
        int i{};
        while (ans[i] == 0) ++i; // 略过前导零
        string s{};              // 放字符串的结果
        while (i < N) s.push_back(ans[i++] + '0');
        return s;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"s;
        int m = num1.size(), n = num2.size();
        int N = m + n, arr[N];
        memset(arr, 0, sizeof(arr));

        for (int i = m - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--)
                arr[i + j + 1] += x * (num2[j] - '0');
        }
        // 处理进位
        for (int i = N - 1; i > 0; i--) arr[i - 1] += arr[i] / 10, arr[i] %= 10;

        string ans;
        for (int i = arr[0] == 0; i < N; ++i) ans.push_back(arr[i] + '0');
        return ans;
    }
};


int main(int argc, char const* argv[]) {
    Solution s;
    cout << s.multiply("12", "238") << endl;
    return 0;
}