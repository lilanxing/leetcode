#include <iostream>
#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            if (res > INT_MAX || res < INT_MIN) return 0;
            x /= 10;
        }
        return res;
    }
};

int main() {
    Solution s;
    int x;

    x = 123;
    std::cout << s.reverse(x) << std::endl;

    x = -123;
    std::cout << s.reverse(x) << std::endl;

    x = 120;
    std::cout << s.reverse(x) << std::endl;
    
    return 0;
}
