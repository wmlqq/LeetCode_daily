#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return !(find(nums.begin(), nums.end(), target) == nums.end());
    }
};


#include<vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (nums[mid] == target)return true;
            else if (nums[left] == nums[right]&&nums[right]==nums[mid]) {
                left++;
            }
            else if (nums[left] < nums[mid]) {
                if (nums[left] <= target&&target < nums[mid])right = mid - 1;
                else left = mid + 1;
            }
            else if (nums[mid] < nums[left]) {
                if (nums[right] >= target&&target > nums[mid])left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};