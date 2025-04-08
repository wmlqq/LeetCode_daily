#include<vector>
using namespace std;
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<int>hash(105,0);
            for(int i=nums.size()-1;i>=0;i--){
                if(hash[nums[i]]==0)hash[nums[i]]++;
                else if(hash[nums[i]]==1)return i/3+1;
            }
            return 0;
        }
    };