package main

import (
	"fmt"
	"strings"
)

func convert(s string, numRows int) string {
	if numRows <= 1 {
		return s
	}
	strs := make([]string, numRows, numRows)
	row, step := 0, 1
	for _, _s := range s {
		strs[row] += string(_s)
		if row == 0 {
			step = 1
		} else if (row == numRows - 1) {
			step = -1
		}
		row += step
	}

	return strings.Join(strs, "")
}

func main() {
	var s string

	s = "PAYPALISHIRING"
	fmt.Println(convert(s, 3))

	s = "AB"
	fmt.Println(convert(s, 1))
}
