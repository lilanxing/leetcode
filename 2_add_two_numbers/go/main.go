package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var (
		extra int
		sum   int
	)
	head := &ListNode{Val: 0, Next: nil}
	p := head

	for l1 != nil || l2 != nil || extra > 0 {
		sum = 0
		if l1 != nil {
			sum = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		sum += extra
		p.Next = &ListNode{Val: sum % 10, Next: nil}
		p = p.Next
		extra = sum / 10
	}

	return head.Next
}

func main() {
	l1 := &ListNode{Val: 2}
	l1.Next = &ListNode{Val: 4}
	l1.Next.Next = &ListNode{Val: 3}

	l2 := &ListNode{Val: 5}
	l2.Next = &ListNode{Val: 6}
	l2.Next.Next = &ListNode{Val: 4}

	p := addTwoNumbers(l1, l2)
	for p != nil {
		fmt.Println(p.Val)
		p = p.Next
	}
}
