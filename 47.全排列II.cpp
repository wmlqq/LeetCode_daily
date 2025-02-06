#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        vector<bool>haveused(nums.size(), false);
        vector<int>current;
        stepbystep(nums, result, current, haveused);
        return result;
    }

private:
    void stepbystep(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& haveused) {
        if (current.size() == nums.size()) {
            result.push_back(current); return;
        }
        set<int>samed;
        for (int i = 0; i < nums.size(); i++) {
            if (haveused[i] || samed.count(nums[i]))continue;
            samed.insert(nums[i]);haveused[i] = true;current.push_back(nums[i]);
            stepbystep(nums, result, current, haveused);
            current.pop_back(); haveused[i] = false;
        }
    }
};