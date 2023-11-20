#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        // sort(words.begin(), words.end(),
        //      [](const auto &l, const auto &r) { return l.size() > r.size();
        //      });
        int n = words.size();
        int ans{};
        for (int i{}; i < n; ++i) {
            auto w = words[i];
            unordered_set<char> st(w.begin(), w.end());
            for (int j{i + 1}; j < n; ++j) {
                bool flg = true;
                // int tmp{};
                for (auto c : words[j]) {
                    if (st.count(c)) {
                        flg = false;
                        break;
                    }
                }
                if (flg) {
                    int tmp = w.size() * words[j].size();
                    ans = max(ans, tmp);
                    break;
                }
            }
        }

        return ans;
    }
};
