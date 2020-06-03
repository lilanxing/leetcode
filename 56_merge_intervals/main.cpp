#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
	std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& i1, std::vector<int>& i2) {
	    return i1[0] < i2[0];
	});
	int c = 0;
	for (int i = 0; i < intervals.size();) {
	    int j = i + 1;
	    while (j < intervals.size() && overlap(intervals[i], intervals[j])) {
		mergeTwoIntervals(intervals[i], intervals[j++]);
	    }
	    intervals[c++] = intervals[i];
	    i = j;
	}

	return std::vector<std::vector<int>>(intervals.begin(), intervals.begin() + c);
    }

    bool overlap(const std::vector<int>& i1, const std::vector<int>& i2) {
	return i1[1] >= i2[0];
    }

    void mergeTwoIntervals(std::vector<int>& i1, const std::vector<int>& i2) {
	i1[1] = std::max(i1[1], i2[1]);
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> res = s.merge(intervals);

    std::vector<std::vector<int>>::const_iterator iter = res.begin();
    while (iter != res.end()) {
	std::cout << "[" << (*iter)[0] << ", " << (*iter)[1] << "]" << std::endl;
	iter++;
    }
}
