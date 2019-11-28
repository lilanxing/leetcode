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

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> CombinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> combs;
	std::vector<int> eles;
	std::sort(combs.begin(), combs.end());
	__Backtrack(combs, eles, candidates, target, 0);
        return combs;
    }

    void __Backtrack(std::vector<std::vector<int>>& combs, std::vector<int>& eles, std::vector<int>& candidates, int remain, int start) {
	if (remain < 0) return;
	else if (remain == 0) {
	    std::vector<int> temp(eles);
	    combs.push_back(temp);
	} else {
	    for (int i = start; i < candidates.size(); ++i) {
		eles.push_back(candidates[i]);
		__Backtrack(combs, eles, candidates, remain - candidates[i], i);
		eles.pop_back();
	    }
	}
    }
};

int main() {
    Solution s;
    std::vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    std::vector<std::vector<int>> combs = s.CombinationSum(candidates, target);
    for (int i = 0; i < combs.size(); ++i) {
	for (int j = 0; j < combs[i].size(); ++j) {
	    std::cout << combs[i][j] << " ";
	}
	std::cout << std::endl;
    }

    return 0;
}
