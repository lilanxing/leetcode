/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example:
 * Input: nums = [4,5,6,7,0,1,2], target = 0 Output: 4
 */

#include <vector>
#include <iostream>

class Solution {
public:
    int Search(std::vector<int>& nums, const int target) {
	int left = 0, right = nums.size() - 1;

	while (left <= right) {
	    int mid = (left + right) / 2;
	    if (nums[mid] == target) return mid;

	    if (nums[mid] >= nums[left]) {
		if (nums[left] <= target && nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	    } else {
		if (nums[right] >= target && nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	    }
	}

	return -1;
    }
};

int main() {
    std::vector<int> nums{4, 5, 6, 7, 8, 1, 2, 3};
    const int target = 8;

    Solution s;
    int idx = s.Search(nums, target);
    std::cout << idx << std::endl;
    
    return 0;
}
