package main

/* Given a sorted array nums, remove the duplicates in-place such that
 * each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by
 * modifying the input array in-place with O(1) extra memory.
 *
 * Example:
 * Given nums = [1,1,2].
 * Your function should return length = 2, with the first two elements
 * of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the returned length.
 */

import "fmt"

func removeDuplicates(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	count := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i - 1] {
			nums[count] = nums[i]
			count++
		}
	}
	return count
}

func main() {
	nums := []int{1, 1, 2}
	count := removeDuplicates(nums)
	fmt.Println(count)
	fmt.Println(nums)
}
