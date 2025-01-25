#include<vector>

using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size();
        vector<int>dec(n, 0);
        long long lost = 0;
        long long result = 0;
        for (int i = 0; i < n; i++) {
            dec[i] = transactions[i][1] - transactions[i][0];
            if (dec[i] < 0)lost -= dec[i];
        }
        for (int i = 0; i < n; i++) {
            result = max(result, lost + min(transactions[i][0], transactions[i][1]));
        }
        return result;

    }
};