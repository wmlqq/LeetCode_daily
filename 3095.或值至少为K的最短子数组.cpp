#include<vector>

using namespace std;

class Solution {
public:
    //计算OR
    int getOR(vector<int>& nums, int left, int right) {
        int OR = 0;
        for (int i = left; i <= right; i++) {
            OR|= nums[i];
        }
        return OR;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        int minlength = -1;

        for (int right = 0; right < nums.size(); right++){

            if (getOR(nums, left, right) >= k) {
                if (minlength == -1)minlength = right - left + 1;
                else if (minlength > 0)minlength = (right - left + 1) < minlength ? (right - left + 1) : minlength;

                while (left < right) {
                    if (getOR(nums, left + 1, right) >= k) {
                        left++;
                        minlength = min(right - left + 1, minlength);
                    }
                    else break;
                }
            }
        }

        return minlength;
    }
};