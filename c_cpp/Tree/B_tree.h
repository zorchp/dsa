#ifndef BTREE
#define BTREE

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <functional> // 递归lambda


using namespace std;

// 重载<<操作符输出数组
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    if (v.empty()) return os << "[]\n";
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++) {
        os << *it << (it != v.end() - 1 ? ", " : "] ");
    }
    return os;
}


class BTreeNode {
    int n; // 关键字个数
    int t; // 最小度
    bool leaf;
    vector<int> keys;
    vector<BTreeNode*> childs;

public:
    BTreeNode(int _t, bool _leaf)
        : n(0), t(_t), leaf(_leaf), keys(2 * t - 1), childs(2 * t) {}

    void traverse(); // 遍历当前节点内数据
    BTreeNode* search(int k);

    // 插入节点
    void insertNonFull(int k);            // 非满情形直接插入
    void splitChild(int i, BTreeNode* y); // 满了就要分裂子节点

    friend class BTree;
};


class BTree {
    BTreeNode* root;
    int t;

public:
    BTree() : root(nullptr), t(0) {}
    BTree(int _t) : root(nullptr), t(_t) {}
    ~BTree() {}

    BTreeNode* search(int k);
    void traverse();
    void insert(int k);
};
#endif
