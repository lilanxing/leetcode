package main

import (
	"fmt"
)

func divide(dividend, divisor int) int {
	if dividend == -2147483648 && divisor == -1 {
		return 2147483647
	}
	sign1, sign2 := 1, 1
	if dividend < 0 {
		sign1 = -1
		dividend = -dividend
	}
	if divisor < 0 {
		sign2 = -1
		divisor = -divisor
	}

	res := 0
	for dividend >= divisor {
		tmp, c := divisor, 1
		for ; tmp << 1 < dividend; tmp <<= 1 {
			c <<= 1
		}
		dividend -= tmp
		res += c
	}
	if sign1 + sign2 == 0 {
		return -res
	}
	return res
}

func main() {
	fmt.Println(divide(7, -3))
}
