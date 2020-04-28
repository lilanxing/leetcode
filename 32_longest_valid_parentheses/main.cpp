/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 * Input: "(()" Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 * Example 2:
 * Input: ")()())" Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int longestValidParentheses(std::string s) {
	if (s.length() <= 1) return 0;
	int res = 0;
	std::vector<int> longest(s.length(), 0);
	for (int i = 1; i < s.length(); ++i) {
	    if (s[i] != ')') continue;
	    if (s[i - 1] == '(') {
		longest[i] = i >= 2 ? longest[i - 2] + 2 : 2;
		res = std::max(longest[i], res);
	    } else {
		if (i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(') {
		    longest[i] = longest[i - 1] + 2 + (i - longest[i - 1] - 2 >= 0 ? longest[i - longest[i - 1] - 2] : 0);
		    res = std::max(longest[i], res);
		}
	    }
	}
	return res;
    }
};

int main() {
    Solution sl;
    std::string s = ")()())";
    std::cout << sl.longestValidParentheses(s) << std::endl;
}
