package main

import (
	"fmt"
)

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	rev, _x := 0, x
	for _x != 0 {
		rev = rev * 10 + _x % 10
		_x /= 10
	}
	if rev == x {
		return true
	}
	return false
}

func main() {
	var x int

	x = 121
	fmt.Println(isPalindrome(x))

	x = -121
	fmt.Println(isPalindrome(x))

	x = 10
	fmt.Println(isPalindrome(x))
}
