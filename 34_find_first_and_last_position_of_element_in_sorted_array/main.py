# -*- coding: utf-8 -*-

'''
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
Examples:
Input: nums = [5,7,7,8,8,10], target = 8 Output: [3,4]
Input: nums = [5,7,7,8,8,10], target = 6 Output: [-1,-1]
'''


class Solution(object):

    def search_range(self, nums, target):
        result = [-1, -1]
        if len(nums) == 0:
            return result

        low, high, mid = 0, len(nums) - 1, 0
        while low < high:
            mid = (low + high) // 2
            if nums[mid] < target:
                low = mid + 1
            else:
                high = mid
        if nums[low] != target:
            return result
        result[0] = low

        high = len(nums) - 1
        while low < high:
            mid = (low + high) // 2 + 1
            if nums[mid] > target:
                high = mid - 1
            else:
                low = mid
        
        result[1] = high
        return result


if __name__ == '__main__':
    nums = [5, 7, 7, 8, 8, 10]
    target = 8
    s = Solution()
    print(s.search_range(nums, target))
