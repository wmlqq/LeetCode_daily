#include <vector>
#include <numeric>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int result = 0;
        long long n = nums.size();
        vector<long long>prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)prefix[i] += nums[i] + prefix[i - 1];

        unordered_map<long long, long long>left, right;

        for (int i = 0; i < n-1; i++) {
            long long x = prefix[n - 1] - 2 * prefix[i];
            right[x]++;
            if (x == 0)result++;
        }

        for (int i = 0; i < n; i++) {
            long long x = prefix[n - 1] - 2 * prefix[i];
            result = max((long long)result, left[nums[i] - k] + right[k - nums[i]]);
            left[x]++; right[x]--;
        }

        return result;
    }
};