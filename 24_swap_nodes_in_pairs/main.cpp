/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * Example:
 * Given 1->2->3->4, return 2->1->4->3
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
	ListNode** pp = &head;
	ListNode* a;
	ListNode* b;

	while ((a = *pp) && (b = a->next)) {
	    a->next = b->next;
	    b->next = a;
	    *pp = b;
	    pp = &(a->next);
	}

	return head;
    }
};

void Output(ListNode* l) {
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

    Solution s;
    Output(node1);
    node1 = s.swapPairs(node1);
    Output(node1);
}
