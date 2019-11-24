/* Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int SearchInsert(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    std::cout << s.SearchInsert(nums, target) << std::endl;

    nums = {1, 3, 5, 6};
    target = 2;
    std::cout << s.SearchInsert(nums, target) << std::endl;

    nums = {1, 3, 5, 6};
    target = 7;
    std::cout << s.SearchInsert(nums, target) << std::endl;

    nums = {1, 3, 5, 6};
    target = 0;
    std::cout << s.SearchInsert(nums, target) << std::endl;
    
    return 0;
}
