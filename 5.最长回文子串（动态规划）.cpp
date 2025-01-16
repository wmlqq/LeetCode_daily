#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); if (n < 2)return s;
        //使用动态规划
        vector<vector<bool>>dp(n, vector<bool>(n, false));

        //所有单字符都是回文序列
        for (int i = 0; i < n; i++) dp[i][i] = true;

        int start = 0, lengthmax = 1;

        //判断双字符是否为回文序列（相同）
        for (int i = 0; i < n; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i; lengthmax = 2;
            }
        }

        //三个及以上首先要满足两个
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n-length+1; i++) {
                int j = i + length - 1;
                if(s[i]==s[j]&&dp[i+1][j-1]) {
                    dp[i][j] = true;
                    start = i;
                    lengthmax = length;
                }
            }
        }
        return s.substr(start, lengthmax);
    }

};