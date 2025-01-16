#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())return "";

        int start = 0, maxlength = 1;

        for (int i = 0; i < s.size(); i++) {
            //检查奇数回文序列
            int length1 = isaround(s, i, i);

            //检查偶数
            int length2 = isaround(s, i, i + 1);
            int length = max(length1, length2);

            if (length > maxlength) {
                start = i - (length - 1) / 2;
                maxlength = length;
            }
        }
        return s.substr(start, maxlength);

    }

private:
    int isaround(string s, int left, int right) {
        while (left >= 0 && right <= s.size() && s[left] == s[right]) {
            left--; right++;
        }
        return right - left - 1;
    }

};