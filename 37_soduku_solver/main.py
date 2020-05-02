# -*- coding: utf-8 -*-


class Solution(object):
    N = 9

    def solve_soduku(self, board):
        self.solve(board)

    def solve(self, board):
        for i in range(self.N):
            for j in range(self.N):
                if board[i][j] == '.':
                    for c in range(1, 10):
                        if self.is_valid(board, i, j, str(c)):
                            board[i][j] = str(c)
                            if self.solve(board):
                                return True
                            board[i][j] = '.'
                    return False
        return True

    def is_valid(self, board, i, j, c):
        for k in range(self.N):
            if c in (board[i][k], board[k][j]):
                return False
            if board[i // 3 * 3 + k // 3][j // 3 * 3 + k % 3] == c:
                return False
        return True


def print_board(board):
    for i in range(9):
        print('-' * 46)
        for j in range(9):
            print('| ' + board[i][j] + ' '),
        print('|')
    print('-' * 46)


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
    print_board(board)
    s.solve_soduku(board)
    print('*' * 50)
    print_board(board)
