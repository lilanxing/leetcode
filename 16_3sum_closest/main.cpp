/*
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int three_sum_closest(std::vector<int>& nums, int target) {
        const int length = nums.size();
        std::sort(nums.begin(), nums.end());

        int min_dist = INT_MAX;
        int min_sum = 0;

        for (int left = 0; left < length - 2; ++left) {
            int mid = left + 1;
            int right = length - 1;

            while (mid < right) {
                int dist = nums[left] + nums[mid] + nums[right] - target;
                if (dist == 0) return target;
                else {
                    if (std::abs(dist) < min_dist) {
                        min_dist = std::abs(dist);
                        min_sum = target + dist;
                    }
                    if (dist < 0) ++mid;
                    else --right;
                }
            }
        }

        return min_sum;
    }
};

int main () {
    std::vector<int> nums{-1, 2, 1, -4};
    const int target = 1;
    Solution s;
    std::cout << s.three_sum_closest(nums, target) << std::endl;
}
