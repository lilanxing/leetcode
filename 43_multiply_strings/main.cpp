#include <iostream>
#include <string>

class Solution {
public:
    std::string multiply(std::string& num1, std::string& num2) {
	if (num1.length() == 0 || num1 == "0") return "0";
	if (num2.length() == 0 || num2 == "0") return "0";

	
	
	return "0";
    }

    std

    std::string singleMultiply(std::string& num, char ch) {
	const int N = num.length();
	if (ch == '0') {
	    return std::string(N, '0');
	}

	int carry = 0;
	int mantissa = 0;
	std::string mul = "";
	for (int i = N - 1; i >= 0; --i) {
	    int n = (ch - '0') * (num[i] - '0') + carry;
	    carry = n / 10;
	    mantissa = n % 10;
	    mul = std::to_string(mantissa) + mul;
	}

	if (carry != 0) {
	    mul = std::to_string(carry) + mul;
	}

	return mul;
    }
};

int main() {
    Solution sl;

    std::string s = "999";
    std::cout << sl.singleMultiply(s, '9') << std::endl;
}
