#include<queue>
#include<algorithm>
#include<vector>

#define MAX 1000000000

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minHeap;
        long long result=0;
        for (int k = 0; k < nums.size(); k++) {
            minHeap.push(nums[k]);
        }
        while (1) {
            if (minHeap.top() >= k)return result;
            if (minHeap.size() < 2)break;
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            long long newnums = (2 * x + y) < MAX ? (2 * x + y) : MAX;
            minHeap.push(newnums);
            result++;
        }
        return -1;
    }
};