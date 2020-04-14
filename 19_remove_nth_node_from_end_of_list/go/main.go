package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	front, back := head, head
	for i := 0; i < n; i++ {
		front = front.Next
	}
	for front != nil && front.Next != nil {
		front, back = front.Next, back.Next
	}
	if back == head {
		if front != nil {
			back.Next = back.Next.Next
		} else {
			head = head.Next
		}
	} else {
		if back.Next != nil {
			back.Next = back.Next.Next
		}
	}
	
	return head
}

func printLink(head *ListNode) {
	p := head
	for p != nil {
		fmt.Printf("%d ", p.Val)
		p = p.Next
	}
	fmt.Println()
}

func main() {
	node1 := &ListNode{Val: 1, Next: nil}
	node2 := &ListNode{Val: 2, Next: nil}
	node1.Next = node2
	/*node3 := &ListNode{Val: 3, Next: nil}
	node2.Next = node3
	node4 := &ListNode{Val: 4, Next: nil}
	node3.Next = node4
	node5 := &ListNode{Val: 5, Next: nil}
	node4.Next = node5*/

	printLink(node1)
	node1 = removeNthFromEnd(node1, 2)
	printLink(node1)
}
