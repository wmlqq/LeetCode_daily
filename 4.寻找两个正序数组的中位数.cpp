#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>allnums;
        int lengthall = nums1.size() + nums2.size();
        int index1 = (lengthall + 1) / 2-1;
        int index2 = (lengthall + 2) / 2-1;
        for (int i = 0; i < nums1.size(); i++) {
            allnums.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            allnums.push_back(nums2[i]);
        }
        sort(allnums.begin(), allnums.end());
        double result = (double)(allnums[index1] + allnums[index2]) / 2;
        return result;
    }
};