# -*- coding: utf-8 -*-

'''
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
'''

class Solution(object):

    def max_area(self, height):
        low, high = 0, len(height) - 1
        maxarea = min(height[low], height[high]) * (high - low)

        while low < high:
            if height[low] < height[high]:
                low += 1
            else:
                high -= 1

            area = min(height[low], height[high]) * (high - low)
            if area > maxarea:
                maxarea = area

        return maxarea


if __name__ == '__main__':
    height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    s = Solution()
    maxarea = s.max_area(height)
    print(maxarea)

