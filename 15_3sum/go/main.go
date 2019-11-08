package main

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4]
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	result := make([][]int, 0)
	length := len(nums)
	if length < 3 {
		return result
	}

	sort.Ints(nums)
	for left := 0; left < length && nums[left] <= 0; left++ {
		if left > 0 && nums[left] == nums[left - 1] {
			continue
		}
		
		target := -nums[left]
		mid, right := left + 1, length - 1
		for ; mid < right; {
			if nums[mid] + nums[right] == target {
				result = append(result, []int{nums[left], nums[mid], nums[right]})
				tmpMid, tmpRight := nums[mid], nums[right]
				for ; mid < right && nums[mid] == tmpMid; mid++ {}
				for ; mid < right && nums[right] == tmpRight; right-- {}
			} else if nums[mid] + nums[right] < target {
				mid++
			} else {
				right--
			}
		}
	}

	return result
}

func main() {
	nums := []int{-1, 0, 1, 2, -1, -4}
	result := threeSum(nums)
	fmt.Println(result)
}
