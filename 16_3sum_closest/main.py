# -*- coding: utf-8 -*-

'''
Given an array nums of n integers and an integer target, find three integers
in nums such that the sum is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''

import sys


class Solution(object):

    def three_sum_closest(self, nums, target):
        nums.sort()
        length = len(nums)
        min_dist, min_sum = sys.maxint, 0
        for left in range(length - 2):
            mid, right = left + 1, length - 1
            while mid < right:
                dist = nums[left] + nums[mid] + nums[right] - target
                if dist == 0:
                    return target
                if abs(dist) < min_dist:
                    min_dist = abs(dist)
                    min_sum = dist + target
                if dist < 0:
                    mid += 1
                else:
                    right -= 1

        return min_sum


if __name__ == '__main__':
    nums = [-1, 2, 1, -4]
    target = 1
    s = Solution()
    print(s.three_sum_closest(nums, target))

            
