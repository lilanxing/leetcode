#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::vector<int> result;
	std::map<int, int> m;

	for (int i = 0; i < nums.size(); ++i) {
	    if (m.count(target - nums[i]) != 0) {
		result.push_back(m[target - nums[i]]);
		result.push_back(i);
		return result;
	    }
	    m[nums[i]] = i;
	}

	return result;
    }
};

int main() {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    Solution s;
    std::vector<int> result = s.twoSum(nums, 9);
    // std::cout << result.size() << std::endl;
    std::cout << result[0] << " " << result[1] << std::endl;
}
