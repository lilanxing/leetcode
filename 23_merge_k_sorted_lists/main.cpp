#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKSortedLists(std::vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) return NULL;

        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) lists[i] = mergeTwoSortedLists(lists[i], lists[len - 1 - i]);
            len = (len + 1) / 2;
        }
        return lists[0];
    }

    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    std::cout << "23" << std::endl;
}
