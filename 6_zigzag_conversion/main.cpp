/*
1;4205;0c * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 */

#include <iostream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1) return s;

        std::string strs[numRows];
        int row = 0;
        int step = 1;

        for (int i = 0; i < s.size(); ++i) {
            strs[row] += s[i];
            if (row == 0) step = 1;
            else if (row == numRows - 1) step = -1;
            row += step;
        }

        s.clear();
        for (int i = 0; i < numRows; ++i) s += strs[i];
        
        return s;
    }
};

int main() {
    Solution sl;
    
    std::string s = "PAYPALISHIRING";
    std::cout << sl.convert(s, 3) << std::endl;

    s = "AB";
    std::cout << sl.convert(s, 1) << std::endl;
}
