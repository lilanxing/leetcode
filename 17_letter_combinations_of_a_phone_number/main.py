# -*- coding: utf-8 -*-


class Solution(object):

    def letter_combinations(self, digits):
        if digits == '':
            return []

        m = ['0', '1', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        res = ['']

        for d in digits:
            tmp = [x + c for c in m[int(d)] for x in res]
            res = tmp
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.letter_combinations('23'))
