# -*- coding: utf-8 -*-


class Solution(object):

    def roman_to_int(self, s):
        m = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        sum = m.get(s[-1], 0)
        for i in range(len(s) - 2, -1, -1):
            sum += m[s[i]] * (-1 if m.get(s[i], 0) < m.get(s[i + 1], 0) else 1)
        return sum


if __name__ == '__main__':
    s = Solution()
    print(s.roman_to_int('III'))
    print(s.roman_to_int('IV'))
    print(s.roman_to_int('IX'))
    print(s.roman_to_int('LVIII'))
    print(s.roman_to_int('MCMXCIV'))
