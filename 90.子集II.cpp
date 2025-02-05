#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        vector<int>empty_vector;
        addone(result, nums, 0, empty_vector);

        return result;
    }

private:
    void addone(vector<vector<int>>& result, vector<int>& nums, int k,vector<int>&newvector) {
        result.push_back(newvector);
        for (int i = k; i < nums.size(); i++) {
            if (i > k && nums[i] == nums[i - 1])continue;

            newvector.push_back(nums[i]);
            addone(result, nums, i + 1, newvector);
            newvector.pop_back();
        }
    }
};