#include<vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int checklength = n / 4+1;
        for (int i = 0; i < n; i += checklength) {
            auto first = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto last = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (last-first >= checklength)return arr[i];
        }
        return -1;
    }
};