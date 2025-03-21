#include<vector>
using namespace std;

class Solution {
    public:
        long long maximumOr(vector<int>& nums, int k) {
            vector<long long>Or(nums.size()+1,0);
            long long pre=0;
            for(int i=nums.size()-1;i>=0;i--){
                Or[i]=Or[i+1]|nums[i];//表示从i到最后项的或值
            }
            long long result=0,prev=0;
            for(int i=0;i<nums.size();i++){
                result=max(result,pre|((long long)nums[i]<<k)|Or[i+1]);
                pre|=nums[i];
            }
            return result;
        }
    };