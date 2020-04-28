# -*- coding: utf-8 -*-


class Solution(object):

    def divide(self, dividend, divisor):
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        sign1, sign2 = 1, 1
        if dividend < 0:
            sign1 = -1
            dividend = -dividend
        if divisor < 0:
            sign2 = -1
            divisor = -divisor

        res = 0
        while dividend >= divisor:
            tmp, c = divisor, 1
            while tmp << 1 < dividend:
                tmp <<= 1
                c <<= 1
            dividend -= tmp
            res += c
        return -res if sign1 + sign2 == 0 else res


if __name__ == '__main__':
    s = Solution()
    print(s.divide(7, -3))
