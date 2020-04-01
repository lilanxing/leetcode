# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def add_two_numbers(self, l1, l2):
        extra = 0
        head = ListNode(0)
        p = head

        while l1 or l2 or extra:
            sum = (l1.val if l1 else 0) + (l2.val if l2 else 0) + extra
            p.next = ListNode(sum % 10);
            p = p.next
            extra = sum // 10
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return head.next


if __name__ == '__main__':
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    s = Solution()
    head = s.add_two_numbers(l1, l2)
    while head:
        print(head.val,)
        head = head.next
