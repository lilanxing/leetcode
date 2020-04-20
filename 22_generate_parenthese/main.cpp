/*
 * Given n pairs of parentheses, write a function to generate all 
 * combinations of well-formed parentheses.

 * For example, given n = 3, a solution set is:
 *
 * [
 *     "((()))",
 *     "(()())",
 *     "(())()",
 *     "()(())",
 *     "()()()"
 * ]
 */

#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    std::vector<std::string> generateParantheses(int n) {
	std::vector<std::string> res;
	_generate(n, n, "", res);
	return res;
    }

    void _generate(int left_num, int right_num, std::string s, std::vector<std::string>& res) {
	if (left_num == 0 && right_num == 0) res.push_back(s);
	if (left_num > 0) _generate(left_num - 1, right_num, s + '(', res);
	if (right_num > 0 && right_num > left_num) _generate(left_num, right_num - 1, s + ')', res);
    }
};

void Output(const std::vector<std::string>& ss) {
    std::vector<std::string>::const_iterator iter = ss.begin();
    while (iter != ss.end()) {
	std::cout << *iter++ << std::endl;
    }
}

int main() {
    Solution s;
    Output(s.generateParantheses(4));
}
