# -*- coding: utf-8 -*-

'''
Given an array nums and a value val, remove all instances of
that value in-place and return the new length.
Do not allocate extra space for another array, you must do this
by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what
you leave beyond the new length.

Example:
Given nums = [3,2,2,3], val = 3.
Your function should return length = 2, with the first two elements of
nums being 2. It doesn't matter what you leave beyond the returned length.
'''


class Solution(object):

    def remove_element(self, nums, val):
        idx = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[idx] = nums[i]
                idx += 1
        return idx


if __name__ == '__main__':
    nums = [3, 2, 2, 3]
    val = 3
    s = Solution()
    n = s.remove_element(nums, val)
    print(n)
    print(nums)
