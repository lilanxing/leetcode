# -*- coding: utf-8 -*-


class Solution(object):

    def int_to_roman(self, num):
        m = [
            ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'],
            ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'],
            ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'],
            ['', 'M', 'MM', 'MMM']
        ]
        return m[3][num / 1000] + m[2][num % 1000 / 100] + m[1][num % 100 / 10] + m[0][num % 10]


if __name__ == '__main__':
    s = Solution()

    num = 3
    print(s.int_to_roman(num))

    num = 4
    print(s.int_to_roman(num))

    num = 9
    print(s.int_to_roman(num))

    num = 58
    print(s.int_to_roman(num))

    num = 1994
    print(s.int_to_roman(num))
