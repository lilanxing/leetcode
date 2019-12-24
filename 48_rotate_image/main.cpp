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

#include <iostream>
#include <vector>

class Solution {
public:
    void Rotate(std::vector<std::vector<int>>& matrix) {
	const int n = matrix.size();
	std::reverse(matrix.begin(), matrix.end());
	int temp;
	for (int i = 0; i < n; ++i) {
	    for (int j = 0; j < i; ++j) {
		temp = matrix[i][j];
		matrix[i][j] = matrix[j][i];
		matrix[j][i] = temp;
	    }
	}
    }
};

void PrintMatrix(const std::vector<std::vector<int>> matrix) {
    const int n = matrix.size();
    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j) {
	    std::cout << matrix[i][j] << " ";
	}
	std::cout << std::endl;
    }
}

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix = {
	std::vector<int>{1, 2, 3},
	std::vector<int>{4, 5, 6},
	std::vector<int>{7, 8, 9}
    };
    PrintMatrix(matrix);
    s.Rotate(matrix);
    PrintMatrix(matrix);
}
