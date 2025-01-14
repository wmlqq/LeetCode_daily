#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = 0;
        while (true) {
            auto minwhere = min_element(nums.begin(), nums.end());
            if (*minwhere < k) {
                nums.erase(minwhere);
                n++;
            } else {
                break;
            }
        }
        return n;
    }
};
