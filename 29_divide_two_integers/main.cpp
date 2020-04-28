/*
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
 *
 * Example 1:
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 *
 * Example 2:
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * Note:
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
 * For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
 */

#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) return INT_MAX;
	
	long dividend_l = dividend;
	long divisor_l = divisor;
	int sign_dividend = 1;
	int sign_divisor = 1;
	if (dividend < 0) {
	    sign_dividend = -1;
	    dividend_l = -dividend_l;
	}
	if (divisor < 0) {
	    sign_divisor = -1;
	    divisor_l = -divisor_l;
	}

	long res = 0;
	while (dividend_l >= divisor_l) {
	    long tmp = divisor_l, c = 1;
	    while (tmp << 1 <= dividend_l) {
		tmp <<= 1;
		c <<= 1;
	    }
	    dividend_l -= tmp;
	    res += c;
	}
	return sign_dividend + sign_divisor == 0 ? -res : res;
    }
};

int main() {
    Solution s;
    // std::cout << s.divide(10, 3) << std::endl;
    // std::cout << s.divide(7, -3) << std::endl;
    std::cout << s.divide(-1, 1) << std::endl;
}
