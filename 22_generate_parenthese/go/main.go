package main

import (
	"fmt"
)

func generateParenthesis(n int) []string {
	res := make([]string, 0)
	generate(n, n, "", &res);
	return res
}

func generate(left, right int, s string, res *[]string) {
	if left == 0 && right == 0 {
		*res = append(*res, s)
	}
	if left > 0 {
		generate(left - 1, right, s + "(", res)
	}
	if right > 0 && right > left {
		generate(left, right - 1, s + ")", res)
	}
}

func main() {
	fmt.Println(generateParenthesis(3))
}
