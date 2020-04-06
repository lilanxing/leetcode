# -*- coding: utf-8 -*-


class Solution(object):

    def reverse(self, x):
        res = 0
        while x != 0:
            res = res * 10 + abs(x) % 10 * int(x / abs(x))
            if res > 2 ** 31 - 1 or res < -(2 ** 31):
                return 0
            x = abs(x) / 10 * int(x / abs(x))
        return res


if __name__ == '__main__':
    s = Solution()

    x = 321
    print(s.reverse(x))

    x = -123
    print(s.reverse(x))

    x = 120
    print(s.reverse(x))
