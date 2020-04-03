/*
 * Given a string, find the length of the longest substring without repeating characters.
 * Example 1:
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 *
 * Example 2:
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 *
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
	int tmp;
	int window_size = 0, i = 0, j = 1;
	const int size = s.size();
	std::map<char, bool> shown;
	
	while (i < size) {
	    shown[s[i]] = true;
	    while (j < size) {
		if (shown[s[j]]) break;
		shown[s[j++]] = true;
	    }
	    tmp = j - i;
	    window_size = tmp > window_size ? tmp : window_size;
	    if (j >= size) break;	    
	    shown[s[i++]] = false;
	    if (i >= j) j = i + 1;
	}
	
	return window_size;
    }
};

int main() {
    Solution s;
    
    std::string str = "abcabcbb";
    std::cout << s.lengthOfLongestSubstring(str);

    str = "bbbbb";
    std::cout << s.lengthOfLongestSubstring(str);

    str = "pwwkew";
    std::cout << s.lengthOfLongestSubstring(str);
}
