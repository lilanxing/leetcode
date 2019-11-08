/*
 * Given an array nums and a value val, remove all instances of 
 * that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this 
 * by modifying the input array in-place with O(1) extra memory.
 *
 * The order of elements can be changed. It doesn't matter what 
 * you leave beyond the new length.
 *
 * Example:
 * Given nums = [3,2,2,3], val = 3.
 * Your function should return length = 2, with the first two elements of 
 * nums being 2. It doesn't matter what you leave beyond the returned length.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int RemoveElement(std::vector<int>& nums, int val) {
	int idx = 0;
	for (int i = 0; i < nums.size(); ++i) {
	    if (nums[i] != val) nums[idx++] = nums[i];
	}
	
        return idx;
    }
};

int main() {
    std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    const int val = 2;
    Solution s;
    const int n = s.RemoveElement(nums, val);
    std::cout << n << std::endl;
    for (int i = 0; i < nums.size(); ++i) {
	std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}
