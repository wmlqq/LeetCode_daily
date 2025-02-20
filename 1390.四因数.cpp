#include<vector>
using namespace std;
class Solution {
    public:
        int sumFourDivisors(vector<int>& nums) {
            int result=0;
            for(int i=0;i<nums.size();i++){
                vector<int>factors;
                for(int j=1;j*j<=nums[i];j++){
                    if(nums[i]%j==0){
                        factors.push_back(j);
                        if(j*j!=nums[i])factors.push_back(nums[i]/j);
                    }
                    if(factors.size()>4)break;
                }
                if(factors.size()==4){
                    for(int j=0;j<4;j++){
                        result+=factors[j];
                    }
                }
            }
            return result;
        }
    };