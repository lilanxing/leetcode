package main

/*
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers. If such
 * arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 * Examples:
 * 1, 2, 3 -> 1, 3, 2
 * 3, 2, 1 -> 1, 2, 3
 * 1, 1, 5 -> 1, 5, 1
 */

import "fmt"

func nextPermutation(nums []int) {
	n := len(nums)
	i, j := n - 2, n - 1

	for ; i >= 0 && nums[i] >= nums[i + 1]; i-- {}
	if i >= 0 {
		for ; nums[j] <= nums[i]; j-- {}
		nums[i], nums[j] = nums[j], nums[i]
	}
	for left, right := i + 1, n - 1; left < right; left, right = left + 1, right - 1 {
		nums[left], nums[right] = nums[right], nums[left]
	}
}

func main() {
	nums := []int{1, 3, 2}
	nextPermutation(nums)
	fmt.Println(nums)
}
