#include <cstddef>
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unistd.h>


using namespace std;

class LRUCache { // 官方题解版
private:
    // 嵌套类实现双向链表节点(实际存放数据的位置)
    struct Node {
        int key, value;
        Node *prev, *next;
        Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
        Node(int _key, int _val)
            : key(_key), value(_val), prev(nullptr), next(nullptr) {}
    };
    int capacity, size;
    unordered_map<int, Node *> cache; // 缓存位置
    Node *head, *tail;                // 存头尾结点, 便于删除

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 首尾哑结点, 减少边界判断
        head = new Node(), tail = new Node();
        head->next = tail, tail->prev = head;
    }
    void print() {
        cout << "cache: \n";
        for (auto i : cache) cout << i.first << " ";
        cout << "\nlist: \n";
        for (auto i = head; i != nullptr; i = i->next)
            cout << "<" << i->key << " " << i->value << "> ";
        cout << endl;
    }

    // 下面的操作仅针对双向链表(存使用情况与数据)
    void addToHead(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void delNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node *node) {
        delNode(node);
        addToHead(node);
    }

    Node *delTail() { // 删除尾结点
        auto node = tail->prev;
        delNode(node);
        return node;
    }

    // -------------------
    int get(int key) {
        if (!cache.count(key)) return -1;
        // 存入缓存(链表头插入)
        auto node = cache[key]; // 定位节点
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) { // 创建新节点
            auto node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            if (++size > capacity) { // 超出缓存
                auto removed = delTail();
                --size;
                cache.erase(removed->key);
                delete removed;
            }
        } else { // 存在, 先定位
            auto node = cache[key];
            node->value = value;
            moveToHead(node); // 移过去
        }
    }
};


class LRUCache1 { // 使用STL的双向链表list容器实现
private:
    using pii = pair<int, int>;
    using piii = list<pii>::iterator;
    list<pii> lst; // 记录使用情况和实际键值对(数据)
    int capacity, size;
    unordered_map<int, piii> cache{}; // 存键及键指向数据的指针(迭代器)

public:
    LRUCache1(int _capacity) : capacity(_capacity), size(0) {}
    void print() {
        cout << "cache: \n";
        for (auto i : cache) cout << i.first << " ";
        cout << "\nlist: \n";
        for (auto i : lst) cout << "<" << i.first << " " << i.second << "> ";
        cout << endl;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        piii tmp = cache[key];
        // 用过了, 移动到前面
        lst.emplace_front(*tmp);
        lst.erase(tmp);

        cache[key] = lst.begin(); // erase之后, 迭代器失效, 需要重新赋值
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (!cache.count(key)) { // 没有, 添加
            lst.emplace_front(pii{key, value});
            cache[key] = lst.begin();
            if (++size > capacity) {
                cache.erase(lst.back().first); // 通过键删除
                lst.pop_back();
                --size;
            }
        } else { // 修改现有的值
            piii cur = cache[key];
            pii data = *cur;
            data.second = value;
            lst.emplace_front(data);
            lst.erase(cur);
            cache[key] = lst.begin();
        }
    }
};

void t1() {
    //
    LRUCache lru(2);
    lru.put(1, 1);              // 缓存是 {1=1}
    lru.put(2, 2);              // 缓存是 {1=1, 2=2}

    cout << lru.get(1) << endl; // 返回 1
    lru.print();
    return;

    lru.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lru.print();

    cout << lru.get(2) << endl; // 返回 -1 (未找到)
    lru.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lru.print();

    cout << lru.get(1) << endl; // 返回 -1 (未找到)
    cout << lru.get(3) << endl; // 返回 3
    cout << lru.get(4) << endl; // 返回 4
}

void t2() {
    //
    LRUCache lru(2);
    lru.put(2, 1);              // 缓存是 {1=1}
    lru.put(2, 2);              // 缓存是 {1=1, 2=2}
    cout << lru.get(2) << endl; // 返回 1
    lru.print();

    lru.put(1, 1); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lru.print();

    lru.put(4, 1); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lru.print();

    cout << lru.get(2) << endl; // 返回 -1 (未找到)
}


int main(int argc, char const *argv[]) {
    t1();
    // t2();
    return 0;
}
