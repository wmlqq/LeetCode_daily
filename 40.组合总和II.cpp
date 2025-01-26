#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //递归函数
    void goon(vector<int>& candidates, int target, int begin_index, vector<int>&newres, vector<vector<int>>& result) {
        if (target == 0) {
            if (find(result.begin(), result.end(), newres) == result.end())result.push_back(newres);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = begin_index; i < candidates.size(); i++) {
            if (i > begin_index && candidates[i] == candidates[i - 1])continue;
            newres.push_back(candidates[i]);
            goon(candidates, target - candidates[i], i + 1, newres, result);
            newres.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>newres;
        sort(candidates.begin(), candidates.end());
        int next = 0;
        goon(candidates, target, 0, newres, result);
        return result;

    }
};