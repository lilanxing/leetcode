/*
 * Given a linked list, remove the n-th node from the end of list and
 * return its head. Given n will always be valid.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val) : val(_val), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* back = head;

        for (int i = 0; i < n; ++i) front = front->next;
        while (front && front->next) {
            back = back->next;
            front = front->next;
        }

        if (back == head) {
            if (front) back->next = back->next->next;
            else head = head->next;
        } else {
            back->next = back->next ? back->next->next : NULL;
        }

        return head;
    }
};

void OutputLink(ListNode* head) {
    ListNode* p = head;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    /*ListNode* node3 = new ListNode(3);
    node2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;
    ListNode* node5 = new ListNode(5);
    node4->next = node5;*/
    OutputLink(node1);

    Solution s;
    node1 = s.removeNthFromEnd(node1, 1);
    OutputLink(node1);
}
