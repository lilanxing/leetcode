package main

import (
	"fmt"
	"reflect"
)

func findSubstring(s string, words []string) []int {
	res := make([]int, 0, len(s) / 2)
	if len(words) == 0 || (len(words) > 0 && len(words[0]) == 0) {
		return res
	}
	s_len, e_len := len(words) * len(words[0]), len(words[0])
	words_count := make(map[string]int)
	for _, word := range words {
		words_count[word]++
	}

	for i := 0; i <= len(s) - s_len; i++ {
		if words_count[s[i:i + e_len]] == 0 {
			continue
		}
		ss, tmp_count, skip := s[i:i + s_len], make(map[string]int), false
		for j := 0; j < s_len; j += e_len {
			word := ss[j:j + e_len]
			if words_count[word] == 0 {
				skip = true
				break
			}
			tmp_count[word]++
		}
		if skip {
			continue
		}
		if reflect.DeepEqual(tmp_count, words_count) {
			res = append(res, i)
		}
	}

	return res
}

func main() {
	fmt.Println(findSubstring("barfoothefoobarman", []string{"foo", "bar"}))
}
