#include<vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int minlength = INT_MAX;
        int OR = 0;

        for (int num : nums) {
            if (num > k)return 1;
        }

        for (int right = 0; right < nums.size(); right++) {
            OR |= nums[right];

            if (OR >= k) {
                minlength = min(minlength, right - left + 1);

                while (left < right) {
                    int check = 0;
                    for (int i = left + 1; i <=right; i++)check |= nums[i];

                    if (check >= k) {
                        left++;
                        OR = check;
                        minlength = min(minlength, right - left + 1);
                    }
                    else break;
                }
            }
        }
        return minlength == INT_MAX ? -1 : minlength;
    }
};