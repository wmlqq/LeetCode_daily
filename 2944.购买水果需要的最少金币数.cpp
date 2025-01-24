#include<vector>

using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        vector<int>dp(prices.size(), 0);//dp[i]表示前i+1个物品的最小花费
        dp[0] = prices[0];
        if (prices.size() > 1)dp[1] = prices[0];
        for (int i = 2; i < prices.size(); i++) {
            dp[i] = dp[i - 1]+prices[i];
            for (int k = i / 2; k < i; k++) {
                dp[i] = min(dp[i], dp[k - 1] + prices[k]);
            }
        }
        return dp[prices.size() - 1];
    }
};