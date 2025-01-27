#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        if (n == 0) return "";

        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return s.substr(0, lps[n - 1]);
    }
};