#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)result.push_back(i);
            if (nums[i] > target)return result;
        }
        return result;
    }
};