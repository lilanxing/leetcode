/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * k is a positive integer and is less than or equal to the length of the linked list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void Output(ListNode*);

void OutputV(std::vector<ListNode*> l) {
    std::cout << "vec****";
    for (int i = 0; i < l.size(); ++i) {
        std::cout << l[i]->val << " ";
    }
    std::cout << "****" << std::endl;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        int c = 0;
        while (p && c < k) {
            p = p->next;
            ++c;
        }
        if (c == k) {
            p = reverseKGroup(p, k);
            while (c-- > 0) {
                ListNode* tmp = head->next;
                head->next = p;
                p = head;
                head = tmp;
            }
            head = p;
        }
        return head;
    }
};

void Output(ListNode* l) {
    std::cout << "list: ";
    ListNode* p = l;
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
    ListNode* node3 = new ListNode(3);
    node2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;
    ListNode* node5 = new ListNode(5);
    node4->next = node5;
    Output(node1);

    Solution s;
    node1 = s.reverseKGroup(node1, 2);
    Output(node1);
}
