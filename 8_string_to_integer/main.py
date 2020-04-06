# -*- coding: utf-8 -*-


class Solution(object):

    def my_atoi(self, s):
        if s == '':
            return 0;
        base, sign, i = 0, 1, 0
        while s[i] == ' ':
            i += 1
        if i < len(s) and s[i] in ('-', '+'):
            sign = 1 - 2 * (s[i] == '-')
            i += 1

        while i < len(s) and s[i] >= '0' and s[i] <= '9':
            base = base * 10 + int(s[i])
            if base > 2 ** 31 - 1 or base < -(2 ** 31):
                return 2 ** 31 - 1 if sign == 1 else -(2 ** 31)
            i += 1

        return base * sign


if __name__ == '__main__':
    sl = Solution()

    s = '42'
    print(sl.my_atoi(s))

    s = '   -42'
    print(sl.my_atoi(s))

    s = '4193 with words'
    print(sl.my_atoi(s))

    s = 'words and 987'
    print(sl.my_atoi(s))

    s = '-91283472332'
    print(sl.my_atoi(s))
