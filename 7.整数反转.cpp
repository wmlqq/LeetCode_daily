#include<vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        int check = (x < 0) ? -1 : 1;
        if (x==INT_MIN)return 0;
        x = abs(x);

        while (x != 0) {
            result = result * 10 + x % 10; 
            x /= 10;
        }

        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }

        return check * result; 
    }
};