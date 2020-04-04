# -*- coding: utf-8 -*-


class Solution(object):

    def longest_palindrome(self, s):
        if len(s) < 2:
            return s

        i, max_len, start = 0, 1, 0
        while i < len(s):
            if len(s) - i <= max_len // 2:
                break
            left = right = i
            while right < len(s) - 1 and s[right] == s[right + 1]:
                right += 1
            i = right + 1
            while left > 0 and right < len(s) - 1 and s[left - 1] == s[right + 1]:
                left -= 1
                right += 1

            new_len = right - left + 1
            if new_len > max_len:
                start = left
                max_len = new_len

        return s[start:start + max_len]


if __name__ == '__main__':
    sl = Solution()

    s = 'babad'
    print(sl.longest_palindrome(s))

    s = 'cbbd'
    print(sl.longest_palindrome(s))
