#include<vector>
using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int>result = { 0,INT_MAX };
        for (int i = 1; i * i <= num + 2; i++) {
            int diff = result[1] - result[0];
            if ((num + 1) % i == 0 && (num + 1) / i - i < diff) {
                result[0] = i; result[1] = (num + 1) / i;
                continue;
            }
            if ((num + 2) % i == 0 && (num + 2) / i - i < diff) {
                result[0] = i; result[1] = (num + 2) / i;
            }
        }
        return result;

    }
};