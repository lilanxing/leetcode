#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	while (l1 && l2) {
	    int num;
	    if (l1->val < l2->val) {
		num = l1->val;
		l1 = l1->next;
	    } else {
		num = l2->val;
		l2 = l2->next;
	    }
	    p->next = new ListNode(num);
	    p = p->next;
	}
	p->next = l1 ? l1 : l2;
	return head->next;
    }
};

void OutputList(ListNode* l) {
    ListNode* p = l;
    while (p) {
	std::cout << p->val << " ";
	p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l1_1 = new ListNode(2);
    l1->next = l1_1;
    ListNode* l1_2 = new ListNode(4);
    l1_1->next = l1_2;

    ListNode* l2 = new ListNode(1);
    ListNode* l2_1 = new ListNode(3);
    l2->next = l2_1;
    ListNode* l2_2 = new ListNode(4);
    l2_1->next = l2_2;

    Solution s;
    OutputList(s.mergeTwoSortedLists(l1, l2));
}
