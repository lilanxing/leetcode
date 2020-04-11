#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;
        if (digits.size() <= 0) return res;

        const int N = 10;
        std::string m[N] = {"0", "1", "abc", "def", "ghi", "jkl", "mon", "pqrs", "tuv", "wzyx"};
        std::string cell;
        res.push_back("");

        for (int i = 0; i < digits.size(); ++i) {
            cell = m[digits[i] - '0'];
            std::vector<std::string> temp;
            for (int ch = 0; ch < cell.size(); ++ch) {
                for (int r = 0; r < res.size(); ++r) {
                    temp.push_back(res[r] + cell[ch]);
                }
            }
            res = temp;
        }
        return res;
    }
};

void printStringArray(const std::vector<std::string>& arr) {
    std::vector<std::string>::const_iterator iter = arr.begin();
    while (iter != arr.end()) std::cout << *iter++ << std::endl;
}

int main() {
    Solution s;
    printStringArray(s.letterCombinations("23"));
    return 0;
}

