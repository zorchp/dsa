#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <string>
#include <cstdlib>
#include <initializer_list>
using namespace std;

namespace stl {
template <class T>
ostream& operator<<(ostream& os, const list<T>& l) {
    if (l.empty()) return os << "∅\n";
    for (auto& i : l) os << i << " ";
    return os << endl;
}

template <typename T>
list<T> quick_sort_STL(list<T> input) {
    if (input.empty()) return input;
    list<T> ans{};
    ans.splice(ans.begin(), input, input.begin()); // 首元素放置给 ans
    T const& pivot = *ans.begin();

    // 分割点为(待)插入 pivot 的位置
    auto divide_point = std::partition(input.begin(), input.end(),
                                       [&](T const& t) { return t < pivot; });
    // cout << input;
    // cout << *divide_point;
    list<T> lower_part;
    lower_part.splice(lower_part.begin(), input, input.begin(), divide_point);

    auto new_lower(quick_sort_STL(std::move(lower_part)));
    auto new_higher(quick_sort_STL(std::move(input)));
    ans.splice(ans.end(), new_higher);
    ans.splice(ans.begin(), new_lower);
    return ans;
}
} // namespace stl

void t1() {
    using namespace stl;
    time_t t;
    int N{10};
    srand((unsigned)time(&t));
    list<int> l;
    for (int i{}; i < N; ++i) l.push_back(rand() % 100);
    cout << quick_sort_STL(l);
}


namespace non_STL {

// 单链表节点定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : ListNode(0, nullptr) {}
    ListNode(int x) : ListNode(x, nullptr) {}
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

ostream& operator<<(ostream& os, ListNode* cur) {
    if (!cur) return os << "∅\n";
    while (cur && cur->next) {
        os << cur->val << " -> ";
        cur = cur->next;
    }
    return os << cur->val << " -> ∅\n";
}

// 快排核心, 返回的是 pivot插入位置的前一个(指针)
ListNode* partition(ListNode* head, ListNode* tail, ListNode*& newHead,
                    ListNode*& newTail) {
    // pivot : tail
    ListNode *pivot(tail), *cur(head), *pre{};
    while (cur != pivot) {
        if (cur->val < pivot->val) {
            if (!newHead) newHead = cur;
            pre = cur;
            cur = cur->next;
        } else {
            if (pre) pre->next = cur->next;
            auto tmp{cur->next};
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if (!newHead) newHead = pivot;
    newTail = tail;
    return pivot;
}

ListNode* partition2(ListNode* head, ListNode* tail, ListNode*& newHead,
                     ListNode*& newTail) {
    // pivot : head
    ListNode *pivot(head), *cur(head->next), *pre{};
    head->next = nullptr;
    while (cur) {
        if (cur->val < pivot->val) {
            if (!newHead) newHead = cur;
            pre = cur;
            cur = cur->next;
        } else {
            if (pre) pre->next = cur->next;
            auto tmp{cur->next};
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if (!newHead) newHead = pivot;
    newTail = tail;
    return pivot;
}

ListNode* getTail(ListNode* cur) { // 传值, 不改变节点
    while (cur && cur->next) cur = cur->next;
    return cur;
}

ListNode* quick_sort(ListNode* head, ListNode* tail) {
    if (!head || head == tail) return head; // 空链表
    ListNode *newHead{}, *newTail{};
    ListNode* pivot = partition(head, tail, newHead, newTail);

    if (newHead != pivot) {
        ListNode* tmp = newHead;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quick_sort(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quick_sort(pivot->next, newTail);
    return newHead;
}

template <typename T>
ListNode* gen_list(const initializer_list<T>& il) {
    //
    const vector<T> v(il);
    if (v.empty()) return nullptr;
    ListNode *head = new ListNode(v[0]), *cur = head;
    for (int i{1}; i < v.size(); ++i)
        cur->next = new ListNode(v[i]), cur = cur->next;
    return head;
}


void delete_node(ListNode* node) {
    if (!node) {
        cerr << "try to delete null LinkedList\n";
        return;
    }
    cout << "deleting: ";
    while (node && node->next) {
        auto tmp = node->next;
        cout << node->val << " ";
        delete node;
        node = tmp;
    }
    cout << node->val << " ";
    delete node;
    cout << ".\n";
}
} // namespace non_STL

void t2() {
    using namespace non_STL; //
    auto node = gen_list({10, 8, 5, 3, 6, 9});
    cout << node;
    // auto pivot = partition(node, nullptr, 6);
    // cout << pivot;
    cout << "sorting...\n";
    node = quick_sort(node, getTail(node));
    cout << node;
    delete_node(node);
}


int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
