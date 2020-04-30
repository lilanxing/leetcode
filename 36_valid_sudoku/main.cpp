#include <iostream>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
	const int N = 9;
	int used_column[N][N] = {false};
	int used_row[N][N] = {false};
	int used_block[N][N] = {false};

	for (int i = 0; i < N; ++i) {
	    for (int j = 0; j < N; ++j) {
		if (board[i][j] == '.') continue;
		int num = board[i][j] - '0' - 1;
		int block = i / 3 * 3 + j / 3;
		if (used_column[i][num] || used_row[j][num] || used_block[block][num]) return false;
		used_column[i][num] = used_row[j][num] = used_block[block][num] = true;
	    }
	}

	return true;
    }
};

int main() {
    std::vector<std::vector<char>> board = {
	{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution s;
    std::cout << s.isValidSudoku(board) << std::endl;
    
    return 0;
}
