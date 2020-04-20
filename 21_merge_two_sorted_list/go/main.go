package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoSortedLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{Val: 0}
	p := head

	var num int
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			num = l1.Val
			l1 = l1.Next
		} else {
			num = l2.Val
			l2 = l2.Next
		}
		p.Next = &ListNode{Val: num}
		p = p.Next
	}
	if l1 != nil {
		p.Next = l1
	} else {
		p.Next = l2
	}
	return head.Next
}

func printList(l *ListNode) {
	p := l
	for p != nil {
		fmt.Printf("%d ", p.Val)
		p = p.Next
	}
	fmt.Println()
}

func main() {
	l1 := &ListNode{Val: 1}
	l1_1 := &ListNode{Val: 2}
	l1.Next = l1_1
	l1_2 := &ListNode{Val: 4}
	l1_1.Next = l1_2

	l2 := &ListNode{Val: 1}
	l2_1 := &ListNode{Val: 3}
	l2.Next = l2_1
	l2_2 := &ListNode{Val: 4}
	l2_1.Next = l2_2

	printList(mergeTwoSortedLists(l1, l2))
}
