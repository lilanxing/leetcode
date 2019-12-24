package main

/*
 * You are given an n*n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Note:
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix
 * directly. DO NOT allocate another 2D matrix and do the rotation.
 * Example:
 * Given input matrix =
 * [
 *     [1, 2, 3],
 *     [4, 5, 6],
 *     [7, 8, 9]
 * ],
 * rotate the input matrix in-place such that it becomes:
 * [
 *     [7, 4, 1],
 *     [8, 5, 2],
 *     [9, 6, 3]
 * ]
 */

import "fmt"

func rotate(matrix [][]int) {
	n := len(matrix)
	for i, j := 0, n - 1; i < j; i, j = i + 1, j - 1 {
		matrix[i], matrix[j] = matrix[j], matrix[i]
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}

func main() {
	matrix := [][]int{
		[]int{1, 2, 3},
		[]int{4, 5, 6},
		[]int{7, 8, 9},
	}
	fmt.Printf("%v\n", matrix)
	rotate(matrix)
	fmt.Printf("%v\n", matrix)
}
