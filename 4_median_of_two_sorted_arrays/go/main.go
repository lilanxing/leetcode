package main

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/


import (
	"fmt"
	"math"
)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums1) == 0 {
		return medianOfArray(nums2)
	}
	if len(nums2) == 0 {
		return medianOfArray(nums1)
	}

	n, m := len(nums1), len(nums2)
	if n > m {
		return findMedianSortedArrays(nums2, nums1)
	}

	var l1, l2, r1, r2, c1, c2 int
	low, high := 0, n * 2

	for ; low <= high; {
		c1 = (low + high) / 2
		c2 = m + n - c1
		if c1 == 0 {
			l1 = math.MinInt64
		} else {
			l1 = nums1[(c1 - 1) / 2]
		}
		if c1 == n * 2 {
			r1 = math.MaxInt64
		} else {
			r1 = nums1[c1 / 2]
		}
		if c2 == 0 {
			l2 = math.MinInt64
		} else {
			l2 = nums2[(c2 - 1) / 2]
		}
		if c2 == m * 2 {
			r2 = math.MaxInt64
		} else {
			r2 = nums2[c2 / 2]
		}

		if l1 > r2 {
			high = c1 - 1
		} else if l2 > r1 {
			low = c1 + 1
		} else {
			break
		}
	}
	
	return (math.Max(float64(l1), float64(l2)) + math.Min(float64(r1),float64(r2))) * 0.5
}

func medianOfArray(nums []int) float64 {
	size := len(nums)
	if size == 0 {
		return -1
	}
	return float64((nums[size / 2] + nums[(size - 1) / 2])) * 0.5
}

func main() {
	nums1 := []int{1, 3}
	nums2 := []int{2}
	m := findMedianSortedArrays(nums1, nums2)
	fmt.Println(m)
}
