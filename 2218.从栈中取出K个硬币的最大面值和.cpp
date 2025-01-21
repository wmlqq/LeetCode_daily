#include<vector>

using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            vector<int>& current_pile = piles[i - 1];
            int pile_size = current_pile.size();

            vector<int> prefix_sum(pile_size + 1, 0);
            for (int j = 1; j <= pile_size; ++j) {
                prefix_sum[j] = prefix_sum[j - 1] + current_pile[j - 1];
            }

            for (int j = 0; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j];
                for (int x = 1; x <= min(j, pile_size); ++x) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + prefix_sum[x]);
                }
            }
        }
        return dp[n][k];
    }
};