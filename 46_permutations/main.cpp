#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
	std::vector<std::vector<int>> res;
	std::vector<int> cur;
	permuteCore(nums, res, cur);
	return res;
    }

    void permuteCore(std::vector<int>& nums, std::vector<std::vector<int>>& res, std::vector<int>& cur) {
	if (cur.size() == nums.size()) {
	    res.push_back(cur);
	} else {
	    for (int i = 0; i < nums.size(); ++i) {
		if (std::find(cur.begin(), cur.end(), nums[i]) != cur.end()) {
		    continue;
		}
		cur.push_back(nums[i]);
		permuteCore(nums, res, cur);
		cur.pop_back();
	    }
	}
    }
};

void OutputDoubleVector(const std::vector<std::vector<int>>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
	for (int j = 0; j < vec[i].size(); ++j) {
	    std::cout << vec[i][j] << " ";
	}
	std::cout << std::endl;
    }
}

int main() {
    Solution s;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> res = s.permute(nums);
    OutputDoubleVector(res);
}
