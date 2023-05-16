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
};


int main(int argc, char const* argv[]) {
    //
    return 0;
}