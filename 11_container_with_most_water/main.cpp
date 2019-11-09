/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int MaxArea(std::vector<int>& height) {
	int low = 0;
	int high = height.size() - 1;
	int max_area = std::min(height[low], height[high]) * (high - low);
	int area = 0;

	while (low < high) {
	    if (height[low] < height[high]) ++low;
	    else --high;
	    area = std::min(height[low], height[high]) * (high - low);
	    if (area > max_area) max_area = area;
	}
	
        return max_area;
    }
};

int main() {
    std::vector<int> height;
    height.push_back(1);
    height.push_back(8);
    height.push_back(6);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    height.push_back(8);
    height.push_back(3);
    height.push_back(7);

    Solution s;
    const int max_area = s.MaxArea(height);
    std::cout << max_area << std::endl;

    std::vector<std::vector<int>> a;
}
