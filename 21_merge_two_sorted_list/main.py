# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def merge_two_sorted_lists(self, l1, l2):
        head = ListNode(0);
        p = head;

        while l1 is not None and l2 is not None:
            num = 0
            if l1.val < l2.val:
                num = l1.val
                l1 = l1.next
            else:
                num = l2.val
                l2 = l2.next
            p.next = ListNode(num)
            p = p.next

        p.next = l1 if l1 is not None else l2
        return head.next


def print_list(l):
    p = l
    while p is not None:
        print(p.val)
        p = p.next
    

if __name__ == '__main__':
    l1 = ListNode(1)
    l1_1 = ListNode(2)
    l1.next = l1_1
    l1_2 = ListNode(4)
    l1_1.next = l1_2

    l2 = ListNode(1)
    l2_1 = ListNode(3)
    l2.next = l2_1
    l2_2 = ListNode(4)
    l2_1.next = l2_2

    s = Solution()
    print_list(s.merge_two_sorted_lists(l1, l2))
