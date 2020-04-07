# -*- coding: utf-8 -*-


class Solution(object):

    def is_palindrome(self, x):
        if x < 0:
            return False
        _x, rev = x, 0
        while _x != 0:
            rev = rev * 10 + _x % 10
            _x //= 10
        return True if rev == x else False


if __name__ == '__main__':
    s = Solution()

    x = 121
    print(s.is_palindrome(x))

    x = -121
    print(s.is_palindrome(x))

    x = 10
    print(s.is_palindrome(x))
