#include <iostream>
#include <map>

class Solution {
public:
    int romanToInt(std::string s) {
	std::map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
	int sum = m[s.back()];
	for (int i = s.length() - 2; i >=0; --i) {
	    if (m[s[i]] < m[s[i + 1]]) sum -= m[s[i]];
	    else sum += m[s[i]];
	}
	return sum;
    }
};

int main() {
    Solution s;
    std::cout << s.romanToInt("III") << std::endl;
    std::cout << s.romanToInt("IV") << std::endl;
    std::cout << s.romanToInt("IX") << std::endl;
    std::cout << s.romanToInt("LVIII") << std::endl;
    std::cout << s.romanToInt("MCMXCIV") << std::endl;
}
