package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func output(l *ListNode) {
	for p := l; p != nil; p = p.Next {
		fmt.Printf("%d ", p.Val)
	}
	fmt.Println()
}

func swapPairs(head *ListNode) *ListNode {
	pp := &head
	for *pp != nil && (*pp).Next != nil {
		a := *pp
		b := a.Next
		a.Next = b.Next
		b.Next = a
		*pp = b
		pp = &(a.Next)
	}
	return head
}

func main() {
	node1 := &ListNode{Val: 1}
	node2 := &ListNode{Val: 2}
	node1.Next = node2
	node3 := &ListNode{Val: 3}
	node2.Next = node3
	node4 := &ListNode{Val: 4}
	node3.Next = node4

	output(node1)
	node1 = swapPairs(node1)
	output(node1)
}
