class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto merge = [](ListNode* l1, ListNode* l2) {
            auto dum(new ListNode), cur(dum);
            while (l1 && l2) {
                if (l1->val < l2->val)
                    cur->next = l1, l1 = l1->next;
                else
                    cur->next = l2, l2 = l2->next;
                cur = cur->next;
            }
            cur->next = l1 ? l1 : l2;
            return dum->next;
        };
        int n{};
        auto tmp(head);
        while (tmp) ++n, tmp = tmp->next;
        auto dum(new ListNode(0, head));
        // 迭代
        for (int i{1}; i < n; i <<= 1) {
            auto pre(dum), cur(dum->next);
            while (cur) {
                auto head1(cur);
                for (int j{1}; j < i && cur->next; ++j) cur = cur->next;
                auto head2(cur->next);
                cur->next = nullptr; // 第一段后面的元素断开
                cur = head2;
                for (int j{1}; j < i && cur && cur->next; ++j) cur = cur->next;
                ListNode* next{}; // 剩下的元素(如果有)
                if (cur) next = cur->next, cur->next = nullptr;
                pre->next = merge(head1, head2);
                while (pre->next) pre = pre->next;
                cur = next;
            }
        }
        return dum->next;
    }
};