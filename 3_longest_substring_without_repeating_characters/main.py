# -*- coding: utf-8 -*-


class Solution(object):

    def length_of_longest_substring(self, s):
        i, j = 0, 1
        max_len = 0
        size = len(s)
        shown = dict()

        while i < size:
            shown[s[i]] = True
            while j < size:
                if shown.get(s[j], False):
                    break
                shown[s[j]] = True
                j += 1

            max_len = max(j - i, max_len)
            if j >= size:
                break
            shown[s[i]] = False
            i += 1
            if i >= j:
                j = i + 1

        return max_len


if __name__ == '__main__':
    sl = Solution()

    s = 'abcabcbb'
    print(sl.length_of_longest_substring(s))

    s = 'bbbbb'
    print(sl.length_of_longest_substring(s))

    s = 'pwwkew'
    print(sl.length_of_longest_substring(s))
