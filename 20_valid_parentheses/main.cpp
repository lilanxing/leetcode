/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 */

#include <iostream>
#include <stack>
#include <map>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() % 2 != 0) return false;

        std::map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};
        std::stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else if (!st.empty() && brackets[s[i]] == st.top()) st.pop();
        }
        
        return st.empty();
    }
};

int main() {
    Solution s;
    std::cout << s.isValid("()") << std::endl;
    std::cout << s.isValid("()[]{}") << std::endl;
    std::cout << s.isValid("(]") << std::endl;
    std::cout << s.isValid("([)]") << std::endl;
    std::cout << s.isValid("{[]}") << std::endl;
    std::cout << s.isValid("){") << std::endl;
}
