package main

import (
	"fmt"
)

func longestPalindrome(s string) string {
	if len(s) < 2 {
		return s
	}

	var (
		left    int
		right   int
		new_len int
		start   int
	)
	i, max_len := 0, 1

	for i < len(s) {
		if len(s) - i <= max_len / 2 {
			break
		}

		left, right = i, i
		for right < len(s) - 1 && s[right] == s[right + 1] {
			right++
		}
		i = right + 1

		for left > 0 && right < len(s) - 1 && s[left - 1] == s[right + 1] {
			left--
			right++
		}

		new_len = right - left + 1
		if new_len > max_len {
			start = left
			max_len = new_len
		}
	}
	return s[start:start + max_len]
}

func main() {
	s := "babad"
	fmt.Println(longestPalindrome(s))

	s = "cbbd"
	fmt.Println(longestPalindrome(s))
}
