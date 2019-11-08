/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4]
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> ThreeSum(std::vector<int>& nums) {
	std::vector<std::vector<int>> result;
	if (nums.size() < 3) return result;

	// sort first
	std::sort(nums.begin(), nums.end());
	for (int left = 0; left < nums.size() - 2 && nums[left] < 0; ++left) {
	    if (left > 0 && nums[left] == nums[left - 1]) continue;
	    
	    const int target = -nums[left];
	    int mid = left + 1;
	    int right = nums.size() - 1;
	    while (mid < right) {
		if (nums[mid] + nums[right] == target) {
		    result.push_back(std::vector<int>{nums[left], nums[mid], nums[right]});

		    const int tmp_mid = nums[mid];
		    const int tmp_right = nums[right];
		    while (mid < right && nums[++mid] == tmp_mid);
		    while (mid < right && nums[--right] == tmp_right);
		} else if (nums[mid] + nums[right] < target) {
		    ++mid;
		} else {
		    --right;
		}
	    }
	}
	
        return result;
    }
};

int main() {
    std::vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);

    Solution s;
    std::vector<std::vector<int>> result = s.ThreeSum(nums);
    std::vector<std::vector<int>>::iterator iter = result.begin();
    while (iter != result.end()) {
	std::vector<int>::iterator inner_it = (*iter).begin();
	while (inner_it != (*iter).end() - 1) {
	    std::cout << *inner_it << " ";
	    ++inner_it;
	}
	std::cout << *inner_it << std::endl;
	++iter;
    }
}
