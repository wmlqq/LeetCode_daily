#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        vector<int>dp(n,INT_MAX-1);//dp[i]表示从i到n-1所需的最小步数
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; (j <= nums[i]) && (i + j < n); j++) {
                dp[i] = min(1 + dp[i + j], dp[i]);
            }
        }

        return dp[0];
    }
};