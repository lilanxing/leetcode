#include <iostream>
#include <limits.h>

class Solution {
public:
    int myAtoi(std::string str) {
        int sign = 1;
        long base = 0;
        int i = 0;

        while (i < str.size() && str[i] == ' ') ++i;
        if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
            sign = 1 - 2 * (str[i++] == '-');
        }
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            base = base * 10 + (str[i++] - '0');
            if (base > INT_MAX || base < INT_MIN) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        return base * sign;
    }
};

int main() {
    Solution sl;
    std::string s;

    s = "42";
    std::cout << sl.myAtoi(s) << std::endl;

    s = "   -42";
    std::cout << sl.myAtoi(s) << std::endl;

    s = "4193 with words";
    std::cout << sl.myAtoi(s) << std::endl;

    s = "words and 987";
    std::cout << sl.myAtoi(s) << std::endl;

    s = "-91283472332";
    std::cout << sl.myAtoi(s) << std::endl;
    
    return 0;
}
