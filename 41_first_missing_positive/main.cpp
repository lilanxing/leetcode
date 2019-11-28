/* Given an unsorted integer array, find the smallest missing-positive integer.
 * Example1 Input: [1, 2, 0] Output: 3
 * Example2 Input: [3, 4, -1, 1] Output: 2
 * Example3 Input: [7, 8, 9, 11, 12] Output: 1
 * Note: Your algorithm should run in O(n) time and uses constant extra space.
 */

#include <vector>
#include <iostream>

class Solution {
public:
    int FirstMissingPositive(std::vector<int>& nums) {
        int i = 0;
        int temp = 0;
        while (i < nums.size()) {
            std::cout << i << ", " << nums[i] << std::endl;
            if (nums[i] != (i + 1) && nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                temp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[nums[i] - 1] = temp;
            } else {
                ++i;
            }
        }
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return i + 1;
    }
};

int main() {
    Solution s;
    
    std::vector<int> nums = {1, 2, 0};
    std::cout << s.FirstMissingPositive(nums) << std::endl;

    nums = {3, 4, -1, 1};
    std::cout << s.FirstMissingPositive(nums) << std::endl;

    nums = {7, 8, 9, 11, 12};
    std::cout << s.FirstMissingPositive(nums) << std::endl;
    
    return 0;
}
