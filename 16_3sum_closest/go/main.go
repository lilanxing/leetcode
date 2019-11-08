package main

/*
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

import (
	"fmt"
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	length := len(nums)
	min_dist, min_sum := math.MaxInt64, 0

	var mid, right, dist int
	for left := 0; left < length - 2; left++ {
		mid, right = left + 1, length - 1
		for ; mid < right; {
			dist = nums[left] + nums[mid] + nums[right] - target
			if dist == 0 {
				return target
			}
			if dist < 0 {
				if -dist < min_dist {
					min_dist = -dist
					min_sum = dist + target
				}
				mid += 1
			} else {
				if dist < min_dist {
					min_dist = dist
					min_sum = dist + target
				}
				right -= 1
			}
		}
	}

	return min_sum
}

func main() {
	nums := []int{-1, 2, 1, -4}
	target := 1
	fmt.Println(threeSumClosest(nums, target))
}
