package main

import (
	"fmt"
)

func romanToInt(s string) int {
	if s == "" {
		return 0
	}
	m := map[byte]int{'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
	sum := m[s[len(s) - 1]]
	for i := len(s) - 2; i >= 0; i-- {
		if m[s[i]] < m[s[i + 1]] {
			sum -= m[s[i]]
		} else {
			sum += m[s[i]]
		}
	}
	return sum
}

func main() {
	fmt.Println(romanToInt("III"))
	fmt.Println(romanToInt("IV"))
	fmt.Println(romanToInt("IX"))
	fmt.Println(romanToInt("LVIII"))
	fmt.Println(romanToInt("MCMXCIV"))
}
