package main

import (
	"fmt"
)

func lengthOfLongestSubstring(s string) int {
	var maxLen int

	sRunes := []rune(s)
	i, j, size := 0, 1, len(sRunes)
	shown := make(map[rune]bool)

	for i < size {
		shown[sRunes[i]] = true
		for j < size {
			if shown[sRunes[j]] {
				break
			}
			shown[sRunes[j]] = true
			j++
		}
		if (j - i > maxLen) {
			maxLen = j - i
		}
		if (j >= size) {
			break
		}
		shown[sRunes[i]] = false
		i++
		if i >= j {
			j = i + 1
		}
	}

	return maxLen
}

func main() {
	s := "abcabcbb"
	fmt.Println(lengthOfLongestSubstring(s))

	s = "bbbbb"
	fmt.Println(lengthOfLongestSubstring(s))

	s = "pwwkew"
	fmt.Println(lengthOfLongestSubstring(s))
}
