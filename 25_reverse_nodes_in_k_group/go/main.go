package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	p, c := head, 0
	for p != nil && c < k {
		p, c = p.Next, c + 1
	}
	if c == k {
		p = reverseKGroup(p, k)
		for ; c > 0; c-- {
			tmp := head.Next
			head.Next = p
			p = head
			head = tmp
		}
		head = p
	}
	return head
}

func output(l *ListNode) {
	for p := l; p != nil; p = p.Next {
		fmt.Printf("%d ", p.Val)
	}
	fmt.Println()
}

func main() {
	node1 := &ListNode{Val: 1}
	node2 := &ListNode{Val: 2}
	node1.Next = node2
	node3 := &ListNode{Val: 3}
	node2.Next = node3
	node4 := &ListNode{Val: 4}
	node3.Next = node4
	node5 := &ListNode{Val: 5}
	node4.Next = node5
	output(node1)

	node1 = reverseKGroup(node1, 2)
	output(node1)
}
