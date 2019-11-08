# -*- coding: utf-8 -*-

'''
Given a sorted array nums, remove the duplicates in-place such that
each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by
modifying the input array in-place with O(1) extra memory.

Example:
Given nums = [1,1,2].
Your function should return length = 2, with the first two elements
of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.
'''


class Solution(object):

    def remove_duplicates(self, nums):
        if len(nums) < 2: return len(nums)
        count = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[count] = nums[i]
                count += 1
        return count


if __name__ == '__main__':
    nums = [1, 1, 2]
    s = Solution()
    count = s.remove_duplicates(nums)
    print(count)
    print(nums)
