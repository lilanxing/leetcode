# -*- coding: utf-8 -*-

'''
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
'''


class Solution(object):

    def three_sum(self, nums):
        length = len(nums)
        if length < 3:
            return []

        nums.sort()
        result = []
        for left in range(length - 2):
            if nums[left] > 0:
                break
            if left > 0 and nums[left] == nums[left - 1]:
                continue
            mid, right = left + 1, length - 1
            target = -nums[left]
            while mid < right:
                if nums[mid] + nums[right] == target:
                    result.append([nums[left], nums[mid], nums[right]])
                    tmp_mid, tmp_right = nums[mid], nums[right]
                    while mid < right and nums[mid] == tmp_mid:
                        mid += 1
                    while mid < right and nums[right] == tmp_right:
                        right -= 1
                elif nums[mid] + nums[right] < target:
                    mid += 1
                else:
                    right -= 1
        
        return result


if __name__ == '__main__':
    nums = [-1, 0, 1, 2, -1, -4]
    s = Solution()
    print(s.three_sum(nums))

