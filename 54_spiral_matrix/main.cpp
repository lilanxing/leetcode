/*
 * print matrix in clockwise
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
	std::vector<int> res;
	int rows = matrix.size();
	if (rows <= 0) return res;
	int columns = matrix[0].size();
	if (columns <= 0) return res;

	int start = 0;
	while (rows > start * 2 && columns > start * 2) {
	    printMatrixInCircle(matrix, res, rows, columns, start++);
	}
	return res;
    }

    void printMatrixInCircle(const std::vector<std::vector<int>>& matrix, std::vector<int>& res,
			     int rows, int columns, int start) {
	int end_x = columns - start - 1;
	int end_y = rows - start - 1;

	// from left to right
	for (int i = start; i <= end_x; ++i) {
	    res.push_back(matrix[start][i]);
	}

	// from top to bottom
	if (start < end_y) {
	    for (int i = start + 1; i <= end_y; ++i) {
		res.push_back(matrix[i][end_y]);
	    }
	}

	// from right to left
	if (start < end_x && start < end_y) {
	    for (int i = end_x - 1; i >= start; --i) {
		res.push_back(matrix[end_y][i]);
	    }
	}

	// from bottom to top
	if (start < end_x && start < end_y  - 1) {
	    for (int i = end_y - 1; i > start; --i) {
		res.push_back(matrix[i][start]);
	    }
	}
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
    };
    std::vector<int> res = s.spiralOrder(matrix);
    std::vector<int>::const_iterator iter = res.begin();
    while (iter != res.end()) {
	std::cout << *iter++ << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
