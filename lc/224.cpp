#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const stack<T> &st) {
    auto tmp(st);
    if (tmp.empty()) {
        cout << "empty!\n";
        return;
    }
    for (; !tmp.empty(); tmp.pop()) {
        cout << tmp.top() << " ";
    }
    cout << endl;
}


class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> sign;
        int ans{};
        int sig = 1, tmp = 0;
        for (auto it : s) {
            if (isdigit(it)) { // 1
                tmp = tmp * 10 + (it - '0');
            } else if (it == '-' or it == '+') {
                ans += sig * tmp, tmp = 0; // 2
                it == '+' ? sig = 1 : sig = -1;
            } else if (it == '(') {
                num.push(ans);
                sign.push(sig == 1 ? '+' : '-'); // 3
                ans = 0, sig = 1;
            } else if (it == ')') {
                ans += sig * tmp;
                tmp = 0;
                ans *= (sign.top() == '+' ? 1 : -1); // 4
                sign.pop();
                ans += num.top();
                num.pop();
            }
        }
        ans += sig * tmp; // 5
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    string t1 = "(1+(4+5+2)-3)+(6+8)"; // 23
    // t1 = "(1+(2+3)+4-3)";              // 7
    // t1 = "1+2+3+4"; // 10
    // t1 = "1-(     -2)"; // 3
    cout << s.calculate(t1) << endl;
    return 0;
}
