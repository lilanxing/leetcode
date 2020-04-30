package main

import (
	"fmt"
)

func isValidSudoku(board [][]byte) bool {
	const N = 9
	var (
		used_column,
		used_row,
		used_block [N][N]bool
	)

	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if (board[i][j] == '.') {
				continue
			}
			num, block := int(board[i][j] - '0' - 1), i / 3 * 3 + j / 3
			if used_column[i][num] || used_row[j][num] || used_block[block][num] {
				return false
			}
			used_column[i][num], used_row[j][num], used_block[block][num] = true, true, true
		}
	}
	
	return true
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
	fmt.Println(isValidSudoku(board))
}
