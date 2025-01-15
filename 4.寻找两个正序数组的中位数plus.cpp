#include <vector>
#include<limits>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())return findMedianSortedArrays(nums2, nums1);

        int length1 = nums1.size();
        int length2 = nums2.size();
        int left = 0, right = length1;

        while (left <= right) {
            int cutline1 = (left + right + 1) / 2;
            int cutline2 = (length1 + length2+1) / 2-cutline1;

            int max_left1 = (cutline1 == 0) ? INT_MIN : nums1[cutline1 - 1];
            int min_right1 = (cutline1 == length1) ? INT_MAX : nums1[cutline1];
            int max_left2 = (cutline2 == 0) ? INT_MIN : nums2[cutline2 - 1];
            int min_right2 = (cutline2 == length2) ? INT_MAX : nums2[cutline2];

            if (max_left1 <= min_right2 && max_left2 <= min_right1)return ((length1 + length2) % 2 == 1) ? max(max_left1, max_left2) : (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0;

            if (max_left1 > min_right2)right = cutline1 - 1;
            if (max_left2 > min_right1)left = cutline1 + 1;
        }

        return 0.0;

    }
};