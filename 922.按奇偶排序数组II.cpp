#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] % 2) == (i % 2))continue;
            else {
                for (int j = i + 1; j < nums.size(); j++) {
                    if ((nums[j] % 2) == (i % 2) && ((nums[j] % 2) != (j % 2))) {
                        int ex = nums[i]; nums[i] = nums[j]; nums[j] = ex;
                        break;
                    }
                }
            }
        }
        return nums;
    }
};