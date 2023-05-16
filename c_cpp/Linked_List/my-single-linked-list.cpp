
#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node() : Node(0, nullptr) {}
        Node(int _val) : Node(_val, nullptr) {}
        Node(int _val, Node* _next) : val(_val), next(_next) {}
    };
    Node* head;
    size_t size;

public:
    MyLinkedList() : head(new Node), size() {}
    void print() {
        for (auto cur{head->next}; cur; cur = cur->next)
            cout << cur->val << " -> ";
        cout << "∅" << endl;
    }
    int get(int index) {
        //
        if (index < 0 || index >= size) return -1;
        auto cur(head);
        ++index; // 0
        while (index--) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(size, val); }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        //
        auto pre(head);
        ++size;
        while (index--) pre = pre->next;
        auto node = new Node(val, pre->next);
        pre->next = node;
    }

    void deleteAtIndex(int index) {
        //
        if (index < 0 || index >= size) return;
        auto pre(head);
        --size;
        while (index--) pre = pre->next;
        auto tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
    }
};


void t4() {
    /*["MyLinkedList","addAtHead","addAtIndex","addAtTail","addAtHead","addAtIndex","addAtTail","addAtTail","addAtIndex","deleteAtIndex","deleteAtIndex","addAtTail"]
[[],[0],[1,4],[8],[5],[4,3],[0],[5],[6,3],[7],[5],[4]]*/
    MyLinkedList* mll = new MyLinkedList();
    mll->addAtHead(0);
    mll->addAtIndex(1, 4);
    mll->addAtTail(8);
    mll->addAtHead(5);
    // mll->print(); // 5 -> 0 -> 4 -> 8 -> ∅
    mll->addAtIndex(4, 3);
    mll->addAtTail(0);
    mll->addAtTail(5);
    // mll->print(); // 5 -> 0 -> 4 -> 8 -> 3 -> 0 -> 5 -> ∅
    mll->addAtIndex(6, 3); // 5 -> 0 -> 4 -> 8 -> 3 -> 0 -> 3 -> 5 -> ∅
    mll->deleteAtIndex(7); // 5 -> 0 -> 4 -> 8 -> 3 -> 0 -> 3 -> ∅
    mll->deleteAtIndex(5); // 5 -> 0 -> 4 -> 8 -> 3 -> 3 -> ∅
    mll->addAtTail(4);
    mll->print();
}

void t3() {
    /*["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
[[],[0,10],[0,20],[1,30],[0]]*/
    MyLinkedList* mll = new MyLinkedList();
    mll->addAtIndex(0, 10);
    mll->addAtIndex(0, 20);
    mll->addAtIndex(1, 30);
    mll->print();        // 20 -> 30 -> 10 -> ∅
    assert(mll->get(0) == 20);
    cout << mll->get(0); // 20
}
void t2() {
    /*["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
[[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]*/
    MyLinkedList* mll = new MyLinkedList();
    mll->addAtHead(7);
    mll->addAtHead(2);
    mll->addAtHead(1);
    // mll->print(); // 1 -> 2 -> 7 -> ∅
    mll->addAtIndex(3, 0);
    mll->deleteAtIndex(2);
    // mll->print(); // 1 -> 2 -> 0 -> ∅
    mll->addAtHead(6);
    mll->addAtTail(4);
    mll->print();
    assert(mll->get(4) == 4);
    cout << mll->get(4) << endl; // 4

    // mll->print();
    mll->addAtHead(4);
    mll->addAtIndex(5, 0);
    mll->addAtHead(6);
}
void t1() {
    MyLinkedList* mll = new MyLinkedList();
    mll->addAtHead(1);

    mll->addAtTail(3);
    mll->addAtIndex(1, 2); // 链表变为 1->2->3
    // mll->print();
    mll->get(1);           // 返回 2
    mll->deleteAtIndex(0); // 现在，链表变为 1->3
    mll->print();
    cout << mll->get(1);   // 返回 3
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
 