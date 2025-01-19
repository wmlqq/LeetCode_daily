#include<string>
#include<vector>
#define Mod 1000000007
#define asc_0 48

using namespace std;

class Solution {
public:
    int agroupCount(int length, int k) {

        vector<long long>result(max(4,length+1), 0);
        result[0] = 1; result[1] = 1; result[2] = 2; result[3] = 4;

        switch (k) {
        case 3:
            for (int i = 4; i <= length; i++)result[i] = (result[i - 1] + result[i - 2] + result[i - 3]) % Mod;
            return result[length] % Mod;

        case 4:
            for (int i = 4; i <= length; i++) result[i] = (result[i - 1] + result[i - 2] + result[i - 3] + result[i - 4]) % Mod;
            return result[length] % Mod;

        default:return 0;
        }

    }

    int countTexts(string pressedKeys) {
        vector<int>k = { 0,0,3,3,3,3,3,4,3,4 };
        int n = pressedKeys.length();
        long long result = 1;
        for (int i = 0, length = 1; i < n; i++) {
            if (pressedKeys[i + 1] == pressedKeys[i]) {
                length++;
            }
            else {
                result = (result*agroupCount(length, k[pressedKeys[i]-asc_0]))%Mod;
                length = 1;
            }
        }
        return result;
    }

};