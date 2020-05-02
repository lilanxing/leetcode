#include <iostream>
#include <vector>

class Solution {
public:
    int N = 9;
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

    bool solve(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(std::vector<std::vector<char>>& board, int i, int j, char c) {
        for (int k = 0; k < N; ++k) {
            if (board[k][j] == c) return false;
            if (board[i][k] == c) return false;
            if (board[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3] == c) return false;
        }
        return true;
    }
};

void printBoard(const std::vector<std::vector<char>>& board) {
    const int N = 9;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) std::cout << "----";
        std::cout << "--" << std::endl;
        for (int j = 0; j < N; ++j) std::cout << "| " << board[i][j] << " ";
        std::cout << " |" << std::endl;
    }
    for (int k = 0; k < N; ++k) std::cout << "----";
    std::cout << "--" << std::endl;
}

int main() {
    Solution s;
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
    printBoard(board);
    s.solveSudoku(board);
    std::cout << "******************************" << std::endl;
    printBoard(board);
}
