package main

/*
 * Given an array nums and a value val, remove all instances of
 * that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this
 * by modifying the input array in-place with O(1) extra memory.
 *
 * The order of elements can be changed. It doesn't matter what
 * you leave beyond the new length.
 *
 * Example:
 * Given nums = [3,2,2,3], val = 3.
 * Your function should return length = 2, with the first two elements of
 * nums being 2. It doesn't matter what you leave beyond the returned length.
 */

import "fmt"

func removeElement(nums []int, val int) int {
	idx := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[idx] = nums[i]
			idx++
		}
	}
	return idx
}

func main() {
	nums := []int{3, 2, 2, 3}
	val := 3
	n := removeElement(nums, val)
	fmt.Println(n)
	fmt.Println(nums)
}
