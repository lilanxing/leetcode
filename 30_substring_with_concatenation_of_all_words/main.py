# -*- coding: utf-8 -*-


class Solution(object):

    def find_substring(self, s, words):
        res = []
        if len(words) == 0 or (len(words) > 0 and words[0] == ''):
            return res
        words_count = {}
        for word in words:
            if word not in words_count:
                words_count[word] = 0
            words_count[word] += 1

        s_len, e_len = len(words) * len(words[0]), len(words[0])
        for i in range(0, len(s) - s_len + 1):
            if s[i:i + e_len] not in words:
                continue
            ss = s[i:i + s_len]
            tmp_count, skip = {}, False
            for j in range(0, s_len, e_len):
                word = ss[j:j + e_len]
                if word not in words:
                    skip = True
                    break
                if word not in tmp_count:
                    tmp_count[word] = 0
                tmp_count[word] += 1
            if skip:
                continue
            if tmp_count == words_count:
                res.append(i)
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.find_substring('barfoothefoobarman', ['foo', 'bar']))
