#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; 
        vector<int> result; 

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; 
            if (num_map.find(complement) != num_map.end()) {
                result.push_back(num_map[complement]);
                result.push_back(i);
                return result; 
            }
            num_map[nums[i]] = i;
        }
        return result;
    }
};
