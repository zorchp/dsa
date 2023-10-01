#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* next[26];
    bool isEnd;
    Trie() : next(), isEnd() {}
    void add(string s) {
        auto cur(this);
        for (auto& c : s) {
            c -= 'a';
            if (!cur->next[c]) cur->next[c] = new Trie;
            cur = cur->next[c];
        }
        cur->isEnd = true;
    }
    int query1(string s) { // 返回位置
        auto cur(this);
        int n = s.size();
        for (int i{}; i < n; ++i) {
            int c = s[i] - 'a';
            if (!cur->next[c]) break;
            if (cur->next[c]->isEnd) return i + 1;
            cur = cur->next[c];
        }
        return n;
    }
    int query(string s) { // 返回位置
        auto cur(this);
        int n = s.size();
        for (int i{}; i < n; ++i) {
            int c = s[i] - 'a';
            if (!cur) break;
            if (cur->isEnd) return i;
            cur = cur->next[c];
        }
        return n;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& vs, string s) {
        Trie* root = new Trie;
        // 建树
        for (auto t : vs) root->add(t);
        stringstream ss(s);
        string ans{};
        while (ss) {
            string t;
            ss >> t;
            if (t.empty()) break;
            ans += t.substr(0, root->query(t));
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    vector<string> vs{"cat", "bat", "rat"};
    string s1{"the cattle was rattled by the battery"};
    Solution s;
    cout << s.replaceWords(vs, s1) << endl;

    return 0;
}