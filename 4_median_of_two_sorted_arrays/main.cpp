/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	if (nums1.size() == 0) return MedianOfArray(nums2);
	if (nums2.size() == 0) return MedianOfArray(nums1);

	const int n = nums1.size();
	const int m = nums2.size();
	if (n > m) return findMedianSortedArrays(nums2, nums1);

	int l1, l2, r1, r2, c1, c2;
	int low = 0;
	int high = n * 2;

	while (low <= high) {
	    c1 = (low + high) / 2;
	    c2 = m + n - c1;
	    l1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2];
	    r1 = c1 == 2 * n ? INT_MAX : nums1[c1 / 2];
	    l2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2];
	    r2 = c2 == 2 * m ? INT_MAX : nums2[c2 / 2];

	    if (l1 > r2) high = c1 - 1;
	    else if (l2 > r1) low = c1 + 1;
	    else break;
	}

	return (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
    }

    double MedianOfArray(std::vector<int>& nums) {
	const int size = nums.size();
	if (size == 0) {
	    return -1;
	}
	return (nums[size / 2] + nums[(size - 1) / 2]) / 2.0;
    }
};

int main() {
    std::vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(3);

    std::vector<int> nums2;
    nums2.push_back(2);

    Solution s;
    const double m = s.findMedianSortedArrays(nums1, nums2);
    std::cout << m << std::endl;
}
