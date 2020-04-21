package main

import (
	"fmt"
)


type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKSortedLists(lists []*ListNode) *ListNode {
	size := len(lists)
	if size == 0 {
		return nil
	}
	for size > 1 {
		for i := 0; i < size / 2; i++ {
			lists[i] = mergeTwoSortedLists(lists[i], lists[size - 1 - i])
		}
		size = (size + 1) / 2
	}
	return lists[0]
}

func mergeTwoSortedLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	if l1.Val < l2.Val {
		l1.Next = mergeTwoSortedLists(l1.Next, l2)
		return l1
	} else {
		l2.Next = mergeTwoSortedLists(l1, l2.Next)
		return l2
	}
}
