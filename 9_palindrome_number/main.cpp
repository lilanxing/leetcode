/*
 * Determine whether an integer is a palindrome.
 * An integer is a palindrome when it reads the same backward as forward.
 * Without converting the interger to string
 */

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
	if (x < 0) return false;

	int _x = x;
	int rev = 0;
	while (_x != 0) {
	    rev = rev * 10 + _x % 10;
	    _x /= 10;
	}
	if (rev == x) return true;
	return false;
    }
};

int main() {
    Solution s;
    int x;

    x = 121;
    std::cout << s.isPalindrome(x) << std::endl;

    x = -121;
    std::cout << s.isPalindrome(x) << std::endl;

    x = 10;
    std::cout << s.isPalindrome(x) << std::endl;
}
