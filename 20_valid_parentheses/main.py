# -*- coding: utf-8 -*-


class Solution(object):

    def is_valid(self, s):
        if len(s) % 2 != 0:
            return False
        st = []
        m = {')': '(', '}': '{', ']': '['}
        for ch in s:
            if ch in ('(', '{', '['):
                st.append(ch)
            elif len(st) != 0 and m[ch] == st[-1]:
                st.pop()
        return True if len(st) == 0 else False


if __name__ == '__main__':
    s = Solution()
    print(s.is_valid('()'))
    print(s.is_valid(')['))
