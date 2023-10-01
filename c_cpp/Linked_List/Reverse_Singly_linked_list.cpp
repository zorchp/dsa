#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

void print(ListNode *ptr) {
    while (ptr) {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << "∅" << endl;
}

ListNode *reverseList(ListNode *head) {
    if (!head)
        return head;
    auto cur = head;
    ListNode *pre{};
    while (cur) {
        auto tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode *r1(ListNode *head) {
    if (!head || !head->next)
        return head;
    auto ans = r1(head->next);
    head->next->next = head;
    head->next = nullptr;
    return ans;
}

int main(int argc, char const *argv[]) {
    auto l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    // 遍历输出链表
    print(l1);
    // print(reverseList(l1));
    // print(r1(l1));
    auto r2 = [&](auto &&r2, ListNode *node) {
        if (!node || !node->next)
            return node;
        auto ans = r2(r2, node->next);
        node->next->next = node;
        node->next = nullptr;
        return ans;
    };
    print(r2(r2, l1));
    function<ListNode *(ListNode *)> r3 = [&](ListNode *node) {
        if (!node || !node->next)
            return node;
        auto ans = r3(node->next);
        node->next->next = node;
        node->next = nullptr;
        return ans;
    };
    print(r3(l1));

    return 0;
}
