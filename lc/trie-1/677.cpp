class MapSum {
    struct Trie {
        int val;
        Trie* next[26];
        Trie() : val(), next() {}
    };
    Trie* root;
    unordered_map<string, int> cnt;

public:
    MapSum() : root(new Trie), cnt() {}

    void insert(string key, int val) {
        int d{val};
        if (cnt.count(key)) d -= cnt[key];
        cnt[key] = val; // 更新
        auto cur(root);
        for (auto c : key) {
            c -= 'a';
            if (!cur->next[c]) cur->next[c] = new Trie;
            cur = cur->next[c];
            cur->val += d; // 前缀对应的 val 每次都更新
        }
    }

    int sum(string prefix) {
        auto cur(root);
        for (auto c : prefix) {
            c -= 'a';
            if (!cur->next[c]) return 0;
            cur = cur->next[c];
        }
        return cur->val;
    }
};
