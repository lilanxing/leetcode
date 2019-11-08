/* Given a sorted array nums, remove the duplicates in-place such that 
 * each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by 
 * modifying the input array in-place with O(1) extra memory.
 *
 * Example:
 * Given nums = [1,1,2].
 * Your function should return length = 2, with the first two elements 
 * of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the returned length.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
	if (nums.size() < 2) return nums.size();
	int count = 1;
	for (int i = 1; i < nums.size(); ++i) {
	    if (nums[i] != nums[i - 1]) {
		nums[count++] = nums[i];
	    }
	}
	return count;
    }
};

int main() {
    std::vector<int> nums{1, 1, 2};
    Solution s;
    int count = s.removeDuplicates(nums);
    std::cout << count << std::endl;
    std::vector<int>::iterator it = nums.begin();
    while (it != nums.end()) {
	std::cout << *it++ << " ";
    }
    std::cout << std::endl;
}
