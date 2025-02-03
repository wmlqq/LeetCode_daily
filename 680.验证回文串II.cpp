#include<string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int check = 1;
        return oncecheck(s, check);
    }

private:
    bool oncecheck(string s, int check) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                if (!check)return false;
                else {
                    check = 0;
                    return oncecheck(s.substr(left + 1, right - left), check) || oncecheck(s.substr(left, right - left), check);
                }
            }
            left++; right--;
        }
        return true;
    }
};