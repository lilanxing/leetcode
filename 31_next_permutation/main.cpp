/*
 * Implement next permutation, which rearranges numbers into the 
 * lexicographically next greater permutation of numbers. If such
 * arrangement is not possible, it must rearrange it as the lowest 
 * possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 * Examples:
 * 1, 2, 3 -> 1, 3, 2
 * 3, 2, 1 -> 1, 2, 3
 * 1, 1, 5 -> 1, 5, 1
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    void NextPermutation(std::vector<int>& nums) {
	int n = nums.size();
	int i = n - 2;
	int j = n - 1;

	while (i >= 0 && nums[i] >= nums[i + 1]) --i;
	if (i >= 0) {
	    while (nums[j] <= nums[i]) --j;
	    std::swap(nums[j], nums[i]);
	}
	std::reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution s;
    
    std::vector<int> nums1{1, 2, 3};
    s.NextPermutation(nums1);
    for (int i = 0; i < nums1.size(); ++i) std::cout << nums1[i] << " ";
    std::cout << std::endl;

    std::vector<int> nums2{3, 2, 1};
    s.NextPermutation(nums2);
    for (int i = 0; i < nums2.size(); ++i) std::cout << nums2[i] << " ";
    std::cout << std::endl;

    std::vector<int> nums3{4, 2, 0, 2, 3, 2, 0};
    s.NextPermutation(nums3);
    for (int i = 0; i < nums3.size(); ++i) std::cout << nums3[i] << " ";
    std::cout << std::endl;
}
