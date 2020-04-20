# -*- coding: utf-8 -*-


class Solution(object):

    def generate_parenthesis(self, n):
        res = []
        self.generate(n, n, '', res)
        return res

    def generate(self, left_num, right_num, s, res):
        if left_num == 0 and right_num == 0:
            res.append(s)
        if left_num > 0:
            self.generate(left_num - 1, right_num, s + '(', res)
        if right_num > 0 and right_num > left_num:
            self.generate(left_num, right_num - 1, s + ')', res)


if __name__ == '__main__':
    s = Solution()
    print(s.generate_parenthesis(3))
