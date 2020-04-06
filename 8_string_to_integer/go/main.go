package main

import (
	"fmt"
)

func myAtoi(str string) int {
	base, sign, i := 0, 1, 0
	for ; i < len(str) && str[i] == ' '; i++ {}
	if i < len(str) && (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') {
			sign = -1
		}
		i++
	}
	for ; i < len(str) && str[i] >= '0' && str[i] <= '9'; i++ {
		base = base * 10 + int(str[i] - '0')
		if base > 2147483647 || base < -2147483648 {
			if sign == 1 {
				return 2147483647
			}
			return -2147483648
		}
	}
	return base * sign
}

func main() {
	var s string

	s = "42"
	fmt.Println(myAtoi(s))

	s = "   -42"
	fmt.Println(myAtoi(s))

	s = "4193 with words"
	fmt.Println(myAtoi(s))

	s = "words and 987"
	fmt.Println(myAtoi(s))

	s = "-91283472332"
	fmt.Println(myAtoi(s))
}
