#include <bits/stdc++.h>
using namespace std;
class LFUCache {
    struct Node {
        Node() : Node(0, 0, 1, nullptr, nullptr) {}
        Node(int _key, int _val) : Node(_key, _val, 1, nullptr, nullptr) {}
        Node(int _key, int _val, int _cnt, Node* _prev, Node* _next)
            : key(_key), val(_val), cnt(_cnt), prev(_prev), next(_next) {}
        int key, val, cnt;
        Node *prev, *next;
    };
    struct List {
        Node *head, *tail;
        List() : head(new Node), tail(new Node) {
            head->next = tail, tail->prev = head;
        }
        void addToHead(Node* node) {
            node->next = head->next, node->prev = head;
            head->next->prev = node, head->next = node;
        }
        void delNode(Node* node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        bool empty() const { return head->next == tail; }
        Node* getTail() { return !empty() ? tail->prev : nullptr; }
    };
    void inc(Node* node) {
        int freq = node->cnt;
        auto lst = cntMap[freq];
        lst->delNode(node);
        if (freq == min_cnt && lst->empty()) {
            ++min_cnt;
            delete lst->head;
            delete lst->tail;
            cntMap.erase(freq);
        }
        auto next_list = cntMap[freq + 1];
        if (!next_list) {
            next_list = new List;
            cntMap[freq + 1] = next_list;
        }
        ++node->cnt;
        next_list->addToHead(node);
    }

    int capacity, min_cnt;
    unordered_map<int, Node*> cache;
    unordered_map<int, List*> cntMap; // 记录频率

public:
    LFUCache(int _capacity) : capacity(_capacity), min_cnt(0) {}

    int get(int key) {
        if (!cache.count(key)) return -1;
        auto node = cache[key];
        inc(node);
        return node->val;
    }

    void put(int key, int value) {
        if (!capacity) return;
        Node* node{};
        if (cache.count(key)) {
            node = cache[key];
            node->val = value;
            inc(node);
        } else {
            if (cache.size() == capacity) {
                auto min_list = cntMap[min_cnt];
                node = min_list->getTail();
                cache.erase(node->key);
                min_list->delNode(node);
                delete node;
            }
            node = new Node(key, value);
            auto lst = cntMap[1];
            if (!lst) {
                lst = new List;
                cntMap[1] = lst;
            }
            lst->addToHead(node);
            cache[key] = node;
            min_cnt = 1;
        }
    }
};
void t1() {
    //
    // cnt(x) = 键 x 的使用计数
    // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
    LFUCache* lfu = new LFUCache(2);
    lfu->put(1, 1); // cache=[1,_], cnt(1)=1
    lfu->put(2, 2); // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu->get(1);    // 返回 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu->put(3, 3); // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu->get(2);    // 返回 -1（未找到）
    lfu->get(3);    // 返回 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu->put(4, 4); // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu->get(1); // 返回 -1（未找到）
    lfu->get(3); // 返回 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu->get(4); // 返回 4
                // cache=[3,4], cnt(4)=2, cnt(3)=3
}
int main(int argc, char* argv[]) {
    //
    t1();
    return 0;
}
