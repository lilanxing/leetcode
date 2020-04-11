package main

import (
	"fmt"
	"strconv"
)

func letterCombinations(digits string) []string {
	if digits == "" {
		return nil
	}

	m := []string{"0", "1", "abc", "def", "ghi", "jkl", "mon", "pqrs", "tuv", "wzyx"}
	res := []string{""}

	for _, dStr := range digits {
		d, _ := strconv.ParseInt(string(dStr), 10, 64)
		if d < 2 {
			continue
		}
		tmp := make([]string, 0, len(m[d]) * len(res))
		for _, c := range m[d] {
			for _, r := range res {
				tmp = append(tmp, r + string(c))
			}
		}
		res = tmp
	}
	
	return res
}

func main() {
	fmt.Println(letterCombinations("23"))
}
