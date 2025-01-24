#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>left_max(n, INT_MIN);
        vector<int>right_min(n, INT_MAX);
        left_max[0] = nums[0]; right_min[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)left_max[i] = max(left_max[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i--)right_min[i] = min(right_min[i + 1], nums[i]);
        for (int i = 0; i < n - 1; i++) { if (left_max[i] <= right_min[i+1])return (i + 1); }
        return 0;
    }
};