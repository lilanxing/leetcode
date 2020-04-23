# -*- coding: utf-8 -*-


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def reverse_k_group(self, head, k):
        p, c = head, 0
        while p is not None and c < k:
            p, c = p.next, c + 1
        if c == k:
            p = self.reverse_k_group(p, k)
            while c > 0:
                tmp = head.next
                head.next = p
                p = head
                head = tmp
                c -= 1
            head = p
        return head


def output(l):
    p = l
    while p is not None:
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
    node5 = ListNode(5)
    node4.next = node5
    output(node1)

    s = Solution()
    node1 = s.reverse_k_group(node1, 2)
    output(node1)
