# -*- coding: utf-8 -*-

'''
Given a set of candidate numbers(candidates) (without duplicates) and a target number(target),
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
Note:
    All numbers(including target) will be positive integers.
    The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [2, 3, 6, 7], target = 7,
A solution set is:
[[7], [2, 2, 3]]
'''

import copy


class Solution(object):

    def combination_sum(self, candidates, target):
        combs, eles = [], []
        candidates.sort()
        self.__backtrack(combs, eles, candidates, target, 0)
        return combs

    def __backtrack(self, combs, eles, candidates, remain, start):
        if remain < 0:
            return
        elif remain == 0:
           combs.append(copy.deepcopy(eles))
        else:
            for i in range(start, len(candidates)):
                eles.append(candidates[i])
                self.__backtrack(combs, eles, candidates, remain - candidates[i], i)
                del eles[-1]


if __name__ == '__main__':
    s = Solution()
    candidates = [2, 3, 6, 7]
    target = 7
    print(s.combination_sum(candidates, target))
