#include <vector>
#include<queue>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int result = 0;
        priority_queue<int>max_queue;
        for (int i = 0; i < piles.size(); i++) { 
            max_queue.push(piles[i]); 
        }
        for (int i = 0; i < piles.size() / 3; i++) {
            max_queue.pop();
            result += max_queue.top();
            max_queue.pop();
        }
        return result;
    }
};