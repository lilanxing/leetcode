package main

import (
	"fmt"
)

const N = 9

func isValid(board [][]byte, i, j int, c byte) bool {
	for k := 0; k < N; k++ {
		if board[i][k] == c || board[k][j] == c {
			return false
		}
		if board[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3] == c {
			return false
		}
	}
	return true
}

func solve(board [][]byte) bool {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if board[i][j] != '.' {
				continue
			}
			for c := '1'; c <= '9'; c++ {
				if isValid(board, i, j, byte(c)) {
					board[i][j] = byte(c)
					if solve(board) {
						return true
					}
					board[i][j] = '.'
				}
			}
			return false
		}
	}
	return true
}

func solveSudoku(board [][]byte)  {
	solve(board)
}

func printBoard(board [][]byte) {
	for i := 0; i < N; i++ {
		for k := 0; k < N; k++ {
			fmt.Print("----")
		}
		fmt.Print("--\n")
		for j := 0; j < N; j++ {
			fmt.Printf("| %s ", string(board[i][j]))
		}
		fmt.Print("|\n")
	}
	for k := 0; k < N; k++ {
		fmt.Print("----")
	}
	fmt.Print("--\n")
}

func main() {
	board := [][]byte{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	}
	printBoard(board)
	solveSudoku(board)
	printBoard(board)
}
