#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    LFUCache(int _c) : capacity(_c), minFreq() {}

    int get(int key) {
        if (!keyMap.count(key)) return -1;
        auto node = keyMap[key];
        increment(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!capacity) return;
        Node* node{};
        if (keyMap.count(key)) {
            node = keyMap[key];
            node->value = value;
            increment(node);
        } else {
            if (keyMap.size() == capacity) {
                auto minList = freqMap[minFreq];
                node = minList->getTail();
                keyMap.erase(node->key);
                minList->deleteNode(node);
                delete node;
                node = nullptr;
            }
            node = new Node(key, value);
            auto list = freqMap[1];
            if (list == nullptr) {
                list = new List;
                freqMap[1] = list;
            }
            list->insertHead(node);
            keyMap[key] = node;
            minFreq = 1;
        }
    }

private:
    struct Node {
        int key, value, freq;
        Node *pre, *next;
        Node() : Node(0, 0, 1, nullptr, nullptr) {}
        Node(int k, int v) : Node(k, v, 1, nullptr, nullptr) {}
        Node(int k, int v, int f, Node* p, Node* n)
            : key(k), value(v), freq(f), pre(p), next(n) {}
    };
    int capacity, minFreq;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, List*> freqMap;

    struct List {
        Node *head, *tail;
        List() : head(new Node), tail(new Node) {
            head->next = tail, tail->pre = head; // double dummy
        }
        void insertHead(Node* node) {
            node->next = head->next, node->pre = head;
            head->next->pre = node, head->next = node;
        }
        void deleteNode(Node* node) {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        bool isEmpty() { return head->next == tail; }

        Node* getTail() {
            if (isEmpty()) return nullptr;
            return tail->pre;
        }
    };

    void increment(Node* node) {
        int freq = node->freq;
        auto list = freqMap[freq];
        list->deleteNode(node);
        if (freq == minFreq && list->isEmpty()) minFreq = freq + 1;
        auto nextList = freqMap[freq + 1];
        if (nextList == nullptr) {
            nextList = new List;
            freqMap[freq + 1] = nextList;
        }
        ++node->freq;
        nextList->insertHead(node);
    }
};

int main(int argc, char const* argv[]) {
    //
    return 0;
}