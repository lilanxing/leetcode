package main

import (
	"fmt"
)

func longstValidParentheses(s string) int {
	if len(s) <= 1 {
		return 0;
	}
	longest, res := make([]int, len(s)), 0
	for i := 1; i < len(s); i++ {
		if s[i] != ')' {
			continue
		}
		if s[i - 1] == '(' {
			if i < 2 {
				longest[i] = 2
			} else {
				longest[i] = longest[i - 2] + 2
			}
		} else {
			if i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(' {
				longest[i] = longest[i - 1] + 2
				if i - longest[i - 1] - 2 >= 0 {
					longest[i] += longest[i - longest[i - 1] - 2]
				}
			}
		}
		if longest[i] > res {
			res = longest[i]
		}
	}
	return res
}

func main() {
	fmt.Println(longstValidParentheses("(())"))
}
