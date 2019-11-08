/*
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * Examples:
 * Input: nums = [5,7,7,8,8,10], target = 8 Output: [3,4]
 * Input: nums = [5,7,7,8,8,10], target = 6 Output: [-1,-1]
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> SearchRange(std::vector<int>& nums, int target) {
	if (nums.size() == 0) return {-1, -1};
	
	int low = 0, high = nums.size() - 1, mid = 0;
	std::vector<int> result(2, -1);

	while (low < high) {
	    mid = (low + high) / 2;
	    if (nums[mid] < target) low = mid + 1;
	    else high = mid;
	}
	if (nums[low] != target) return result;
	result[0] = low;

	high = nums.size() - 1;
	while (low < high) {
	    mid = (low + high) / 2 + 1;
	    if (nums[mid] > target) high = mid - 1;
	    else low = mid;
	}
	result[1] = high;
	
	return result;
    }
};

int main() {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution s;
    std::vector<int> result = s.SearchRange(nums, target);
    std::cout << result[0] << ", " << result[1] << std::endl;
}
