#include<vector>
using namespace std;
class Solution {
    public:
        int unequalTriplets(vector<int>& nums) {
            int result=0;
            for(int i=0;i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[i]!=nums[j]){
                        for(int k=j+1;k<nums.size();k++){
                            if(nums[j]!=nums[k]&&nums[i]!=nums[k]){
                                result++;
                            }
                        }
                    }
                }
            }
            return result;
        }
    };

#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int unequalTriplets(vector<int>& nums) {
            unordered_map<int, int> num_count;
            vector<int>num;
            int result=0;
            for(int i=0;i<nums.size();i++){
                if(find(num.begin(),num.end(),nums[i])==num.end())num.push_back(nums[i]);
                num_count[nums[i]]++;
            }
            for(int i=0;i<num.size();i++){
                for(int j=i+1;j<num.size();j++){
                    for(int k=j+1;k<num.size();k++){
                        result+=num_count[num[i]]*num_count[num[j]]*num_count[num[k]];
            }
        }
    }
    return result;
}
};