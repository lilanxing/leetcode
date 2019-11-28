package main

/* Given a set of candidate numbers(candidates) (without duplicates) and a target number(target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
 * The same repeated number may be chosen from candidates unlimited number of times.
 * Note:
 *     All numbers(including target) will be positive integers.
 *     The solution set must not contain duplicate combinations.
 * Example 1:
 * Input: candidates = [2, 3, 6, 7], target = 7,
 * A solution set is:
 * [[7], [2, 2, 3]]
 */

import (
	"fmt"
)

func combinationSum(candidates []int, target int) [][]int {
	combs := make([][]int, 0)
	eles := make([]int, 0)
	backtrack(&combs, &eles, candidates, target, 0)
	return combs
}

func backtrack(combs *([][]int), eles *[]int, candidates []int, remain int, start int) {
	if remain < 0 {
		return
	} else if remain == 0 {
		temp := make([]int, len(*eles))
		copy(temp, *eles)
		*combs = append(*combs, temp)
	} else {
		for i := start; i < len(candidates); i++ {
			*eles = append(*eles, candidates[i])
			backtrack(combs, eles, candidates, remain - candidates[i], i)
			*eles = (*eles)[:len(*eles) - 1]
		}
	}
}

func main() {
	candidates := []int{2, 3, 6, 7}
	target := 7
	fmt.Println(combinationSum(candidates, target))
}
