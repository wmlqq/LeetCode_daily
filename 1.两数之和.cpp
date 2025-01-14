#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result(2);
        result[0] = -1;
        for (int k = 0; k < nums.size(); k++) {
            for (int j = k+1; j < nums.size(); j++) {
                if (nums[k] + nums[j] == target) {
                    result[0] = k; result[1] = j;
                }
            }
        }
            if (result[0] == -1) cout << "不存在这两个整数" << endl;
        else cout << "[" << result[0] << "," << result[1] << "]";
            return result;

    }
};
