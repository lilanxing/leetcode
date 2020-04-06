package main

import (
	"fmt"
)

func reverse(x int) int {
	res := 0
	for x != 0 {
		res = res * 10 + x % 10
		if res > 2147483647 || res < -2147483648 {
			return 0
		}
		x /= 10
	}
	return res
}

func main() {
	var x int

	x = 123
	fmt.Println(reverse(x))

	x = -321
	fmt.Println(reverse(x))

	x = 120
	fmt.Println(reverse(x))
}
