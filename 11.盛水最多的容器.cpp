#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxA = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxA = max(maxA, currentArea);

            if (height[left] < height[right])left++;
            else right--;

        }

        return maxA;

    }
};