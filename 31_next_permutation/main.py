# -*- coding: utf-8 -*-

'''
Implement next permutation, which rearranges numbers into the
lexicographically next greater permutation of numbers. If such
arrangement is not possible, it must rearrange it as the lowest
possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Examples:
1, 2, 3 -> 1, 3, 2
3, 2, 1 -> 1, 2, 3
1, 1, 5 -> 1, 5, 1
'''


class Solution(object):

    def next_permutation(self, nums):
        i, j = len(nums) - 2, len(nums) - 1
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        nums[i + 1:] = nums[i + 1:][::-1]


if __name__ == '__main__':
    nums = [1, 3, 2]
    s = Solution()
    s.next_permutation(nums)
    print(nums)
