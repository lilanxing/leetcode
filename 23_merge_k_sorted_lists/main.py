# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def merge_k_sorted_lists(self, lists):
        size = len(lists)
        if size == 0:
            return None
        while size > 1:
            for i in range(size / 2):
                lists[i] = self.merge_two_sorted_lists(lists[i], lists[size - i - 1])
            size = int((size + 1) / 2)
        return lists[0]

    def merge_two_sorted_lists(self, l1, l2):
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        if l1.val < l2.val:
            l1.next = self.merge_two_sorted_lists(l1.next, l2)
            return l1
        else:
            l2.next = self.merge_two_sorted_lists(l1, l2.next)
            return l2
