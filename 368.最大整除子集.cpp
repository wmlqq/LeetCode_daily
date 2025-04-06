#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            vector<vector<int>>dp(nums.size(),vector<int>{});
            sort(nums.begin(),nums.end());

            for(int i=0;i<nums.size();i++){
                dp[i].push_back(nums[i]);
                for(int j=i-1;j>=0;j--){
                    if(dp[i][0]%nums[j]==0)dp[i].insert(dp[i].begin(),nums[j]);
                }
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]%dp[i][dp[i].size()-1]==0)dp[i].push_back(nums[j]);
                }
            }

            int index=0,maxlen=dp[0].size();
            for(int i=1;i<nums.size();i++){
                if(dp[i].size()>maxlen){
                    index=i;
                    maxlen=dp[i].size();
                }
            }
            return dp[index];
        }
    };