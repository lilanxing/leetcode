# -*- coding: utf-8 -*-


class Solution(object):

    def is_valid_sudoku(self, board):
        n = 9
        used_column = [[False] * n for i in range(n)]
        used_row = [[False] * n for i in range(n)]
        used_block = [[False] * n for i in range(n)]

        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    continue
                num, block = int(board[i][j]) - 1, i // 3 * 3 + j // 3
                if used_column[i][num] or used_row[j][num] or used_block[block][num]:
                    return False
                used_column[i][num] = used_row[j][num] = used_block[block][num] = True
        return True


if __name__ == '__main__':
    s = Solution()
    board = [
        ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
        ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
        ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
        ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
        ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
        ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
        ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
        ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
        ['.', '.', '.', '.', '8', '.', '.', '7', '9']
    ]
    print(s.is_valid_sudoku(board))
