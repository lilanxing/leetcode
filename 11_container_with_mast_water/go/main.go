package main

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

import (
	"fmt"
)

func minInt(num1, num2 int) int {
	if num1 < num2 {
		return num1
	}
	return num2
}

func maxArea(height []int) int {
    low, high := 0, len(height) - 1
	maxarea := minInt(height[low], height[high]) * (high - low)
	area := 0

	for ; low < high; {
		if height[low] < height[high] {
			low++
		} else {
			high--
		}
		area = minInt(height[low], height[high]) * (high - low)
		if area > maxarea {
			maxarea = area
		}
	}

	return maxarea
}

func main() {
	height := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	maxarea := maxArea(height)
	fmt.Println(maxarea)
}
