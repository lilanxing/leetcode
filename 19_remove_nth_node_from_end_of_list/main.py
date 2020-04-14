# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, val):
        self.val = val
        self.next = None


class Solution(object):

    def remove_nth_from_end(self, head, n):
        front = back = head
        for i in range(n):
            front = front.next
        while front is not None and front.next is not None:
            front, back = front.next, back.next
        if back == head:
            if front is not None:
                back.next = back.next.next
            else:
                head = head.next
        else:
            back.next = back.next.next if back.next is not None else None

        return head


def print_link(head):
    p = head
    while p is not None:
        print(p.val),
        p = p.next
    print('')
        
    
if __name__ == '__main__':
    node1 = ListNode(1)
    node2 = ListNode(2)
    node1.next = node2
    # node3 = ListNode(3)
    # node2.next = node3
    # node4 = ListNode(4)
    # node3.next = node4
    # node5 = ListNode(5)
    # node4.next = node5
    # print_link(node1)

    s = Solution()
    node1 = s.remove_nth_from_end(node1, 1)
    print_link(node1)
