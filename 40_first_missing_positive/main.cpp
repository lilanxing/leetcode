#include <iostream>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
	bucket(nums);
	const int N = nums.size();
	for (int i = 0; i < N; ++i) {
	    if (nums[i] != i + 1) {
		return i + 1;
	    }
	}
	return N + 1;
    }

    void bucket(std::vector<int>& nums) {
	const int N = nums.size();
	for (int i = 0; i < N; ++i) {
	    if (nums[i] > 0 && nums[i] - 1 < N && nums[i] != nums[nums[i] - 1]) {
		std::swap(nums[i], nums[nums[i] - 1]);
	    }
	}
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {0, -1, 3, 2};
    std::cout << s.firstMissingPositive(nums) << std::endl;
    
    return 0;
}
