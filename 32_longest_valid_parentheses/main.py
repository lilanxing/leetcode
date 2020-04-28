# -*- coding: utf-8 -*-


class Solution(object):

    def longest_valid_parentheses(self, s):
        if len(s) < 2:
            return 0;
        longest = [0] * len(s)
        for i in range(1, len(s)):
            if s[i] != ')':
                continue
            if s[i - 1] == '(':
                longest[i] = 2 if i < 2 else (longest[i - 2] + 2)
            else:
                if i - longest[i - 1] - 1 >= 0 and s[i - longest[i - 1] - 1] == '(':
                    longest[i] = longest[i - 1] + 2 + (longest[i - longest[i - 1] - 2] if i - longest[i - 1] - 2 >= 0 else 0)
        return max(longest)


if __name__ == '__main__':
    s = Solution()
    print(s.longest_valid_parentheses(')()())'))
