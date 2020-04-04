/*
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.

 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 */

#include <iostream>
// #include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
	if (s.size() < 2) return s;

	int start = 0, max_len = 1, new_len = 0;
	int left, right;
	int i = 0;
	while (i < s.size()) {
	    if (s.size() - i <= max_len / 2) break;
	    
	    left = i;
	    right = i;
	    while (right < s.size() - 1 && s[right + 1] == s[right]) ++right;
	    i = right + 1;

	    while (right < s.size() - 1 && left > 0 && s[right + 1] == s[left - 1]) {
		++right;
		--left;
	    }

	    new_len = right - left + 1;
	    if (new_len > max_len) {
		start = left;
		max_len = new_len;
	    }
	}

	return s.substr(start, max_len);
    }
};

int main() {
    Solution sl;

    std::string s = "babad";
    std::cout << sl.longestPalindrome(s) << std::endl;

    s = "cbbd";
    std::cout << sl.longestPalindrome(s) << std::endl;
}
