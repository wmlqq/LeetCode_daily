#include<vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>height(n+1, 0);
        int result = 0;
        for (int i = 1; i < n+1; i++) {
            height[i] = height[i - 1] + gain[i - 1];
            result = max(result, height[i]);
        }
        return result;
    }
};