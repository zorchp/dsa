#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : Node(0) {}
    Node(int v, Node* n = nullptr) : val(v), next(n) {}
};

Node* gen_3() {
    auto head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    return head;
}
Node* gen_4() {
    auto head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    return head;
}

void t1() {
    // auto head = gen_3();
    auto head = gen_4();
    auto f(head), l(head);
    while (f) {
        if (!f->next) {
            cout << "odd\n";
            break;
        }
        f = f->next->next;
        l = l->next;
    }
    cout << l->val;
}


int main(int argc, char* argv[]) {
    t1();
    return 0;
}
