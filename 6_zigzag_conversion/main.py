# -*- coding: utf-8 -*-


class Solution(object):

    def convert(self, s, numRows):
        if numRows <= 1:
            return s
        strs = [''] * numRows
        row, step = 0, 1
        for i in range(len(s)):
            strs[row] += s[i]
            if row == 0:
                step = 1
            elif row == numRows - 1:
                step = -1
            row += step

        return ''.join(strs)


if __name__ == '__main__':
    sl = Solution()

    s = 'PAYPALISHIRING'
    print(sl.convert(s, 3))

    s = 'AB'
    print(sl.convert(s, 1))
