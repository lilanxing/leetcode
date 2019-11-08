# -*- coding: utf-8 -*-

'''
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
'''

import sys


class Solution:

    def find_median_sorted_arrays(self, nums1, nums2):
        if len(nums1) == 0:
            return self.median_of_array(nums2)
        if len(nums2) == 0:
            return self.median_of_array(nums1)

        n, m = len(nums1), len(nums2)
        if n > m:
            return self.find_median_sorted_arrays(nums2, nums1)
        
        low, high = 0, n * 2

        while low <= high:
            c1 = (low + high) // 2
            c2 = m + n - c1
            l1 = -sys.maxint if c1 == 0 else nums1[(c1 - 1) // 2]
            r1 = sys.maxint if c1 == 2 * n else nums1[c1 // 2]
            l2 = -sys.maxint if c2 == 0 else nums2[(c2 - 1) // 2]
            r2 = sys.maxint if c2 == 2 * m else nums2[c2 // 2]

            if l1 > r2:
                high = c1 - 1
            elif l2 > r1:
                low = c1 + 1
            else:
                break
        
        return (max(l1, l2) + min(r1, r2)) * 0.5

    def median_of_array(self.nums):
        size = len(nums)
        if size == 0:
            return -1
        return (nums[size // 2] + nums[(size - 1) // 2]) * 0.5


if __name__ == '__main__':
    nums1 = [1, 3]
    nums2 = [2]
    s = Solution()
    median = s.find_median_sorted_arrays(nums1, nums2)
    print(median)
