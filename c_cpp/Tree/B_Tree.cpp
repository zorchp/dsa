#include "B_tree.h"

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; ++i) {
        if (leaf == false) childs[i]->traverse();
        cout << " " << keys[i];
    }
    if (leaf == false) childs[i]->traverse();
}


BTreeNode* BTreeNode::search(int k) {
    int i{};
    while (i < n && k > keys[i]) ++i;
    if (keys[i] == k) return this;
    if (leaf == true) return nullptr;
    return childs[i]->search(k);
}

void BTreeNode::insertNonFull(int k) {
    int i{n - 1};
    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            --i;
        }
        keys[i + 1] = k;
        ++n;
    } else {
        while (i >= 0 && keys[i] > k) --i;
        if (childs[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, childs[i + 1]);
            if (keys[i + 1] < k) ++i;
        }
        childs[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    auto z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j{}; j < t - 1; ++j) z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
        for (int j{}; j < t - 1; ++j) z->keys[j] = y->keys[j + t];
    }
    y->n = t - 1;

    for (int j{n}; j >= i + 1; --j) childs[j + 1] = childs[j];
    childs[i + 1] = z;
    for (int j{n - 1}; j >= 1; --j) keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    ++n;
}

void BTree::traverse() {
    if (root) root->traverse();
}

BTreeNode* BTree::search(int k) {
    return (root == nullptr) ? nullptr : root->search(k);
}
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            auto s = new BTreeNode(t, false);
            s->childs[0] = root;
            s->splitChild(0, root);
            int i{};
            if (s->keys[0] < k) ++i;
            s->childs[i]->insertNonFull(k);
            root = s;
        } else
            root->insertNonFull(k);
    }
}

int main() {
    BTree t(3); // A B-Tree with minimum degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed tree is ";
    t.traverse();

    int k = 6;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";

    k = 15;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";

    return 0;
}

// void t1() {
//     //
// }

// int main(int argc, char* argv[]) {
//     t1();
//     return 0;
// }
