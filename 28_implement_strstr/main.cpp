/*
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 * Example1:
 * Input: haystack = "hello", needle = "ll" Output: 2
 * Example2:
 * Input: haystack = "aaaaa", needle = "bba" Output: -1
 */

#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
	if (needle == "") return 0;
        int thr = haystack.size() - needle.size();
        for (int i = 0; i <= thr; ++i) {
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    std::cout << s.strStr("", "a") << std::endl;
}
