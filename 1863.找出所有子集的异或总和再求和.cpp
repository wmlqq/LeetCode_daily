#include<vector>
using namespace std;
class Solution {
    public:
        void XOR(vector<int>&nums,int&res,int index,int count){
            if(index>=nums.size()){
                res+=count;
            }
            else{
                XOR(nums,res,index+1,count);
                XOR(nums,res,index+1,count^nums[index]);
                return;
            }
            
        }

        int subsetXORSum(vector<int>& nums) {
            int res=0;
            for(int i=0;i<nums.size();i++){
                XOR(nums,res,i+1,nums[i]);
            }
            return res;
        }
    };