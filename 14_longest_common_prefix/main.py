# -*- coding: utf-8 -*-


class Solution(object):

    def longest_common_prefix(self, strs):
        if len(strs) == 0: return ''
        for i in range(0, len(strs[0])):
            for j in range(1, len(strs)):
                if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                    return strs[0][0:i]
        return strs[0]


if __name__ == '__main__':
    s = Solution()

    strs = ['flower', 'flow', 'flight']
    print(s.longest_common_prefix(strs))

    strs = ['dog', 'racecar', 'car']
    print(s.longest_common_prefix(strs))

    strs = ['aa', 'a']
    print(s.longest_common_prefix(strs))
