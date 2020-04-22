# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def swap_pairs(self, head):
        pre, pre.next = self, head
        while pre.next and pre.next.next:
            a = pre.next
            b = a.next
            pre.next, b.next, a.next = b, a, b.next
            pre = a
        return self.next


def output(l):
    p = l
    while p:
        print(p.val),
        p = p.next
    print('')
    

if __name__ == '__main__':
    node1 = ListNode(1)
    node2 = ListNode(2)
    node1.next = node2
    node3 = ListNode(3)
    node2.next = node3
    node4 = ListNode(4)
    node3.next = node4

    s = Solution()
    output(node1)
    node1 = s.swap_pairs(node1)
    output(node1)
