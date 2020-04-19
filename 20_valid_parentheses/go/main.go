package main

import (
	"fmt"
)

func isValid(s string) bool {
	if len(s) % 2 != 0 {
		return false
	}
	m := map[rune]rune{')': '(', '}': '{', ']': '['}
	st := make([]rune, 0, len(s) / 2)
	for _, ch := range []rune(s) {
		if ch == '(' || ch == '[' || ch == '{' {
			st = append(st, ch)
		} else if l := len(st); l != 0 && st[l - 1] == m[ch] {
			st = st[:l - 1]
		}
	}
	if len(st) == 0 {
		return true
	}
	return false
}

func main() {
	fmt.Println(isValid("()"))
	fmt.Println(isValid("({})"))
	fmt.Println(isValid(")["))
}
