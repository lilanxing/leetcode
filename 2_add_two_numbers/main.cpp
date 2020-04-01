/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example: (2->4->3) + (5->6->4) = (7->0->8)
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(const int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	int extra = 0;
	int sum = 0;

	while (l1 != NULL || l2 != NULL || extra) {
	    sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
	    p->next = new ListNode(sum % 10);
	    p = p->next;
	    extra = sum / 10;
	    l1 = l1 ? l1->next : l1;
	    l2 = l2 ? l2->next : l2;
	}

	return head->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* p = s.addTwoNumbers(l1, l2);
    while (p) {
	std::cout << p->val << " ";
	p = p->next;
    }
    std::cout << std::endl;
    
    return 0;
}
