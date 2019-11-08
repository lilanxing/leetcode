package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	result := make([]int, 2)
	hash := make(map[int]int)
	for i, num := range nums {
		if _, ok := hash[target - num]; ok {
			result[0] = hash[target - num]
			result[1] = i
			return result
		}
		hash[num] = i
	}

	return result
}

func main() {
	nums := []int{2, 7, 11, 15}
	fmt.Println(twoSum(nums, 9))
}
