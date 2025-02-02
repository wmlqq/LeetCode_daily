#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.length();
        int maxlength = 0, length = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ')length++;
            if (s[i] == ' '||i==n-1){
                maxlength = max(maxlength, length); 
                length = 0;
            }
        }
        vector<string>result(maxlength, "");
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ')result[index++] += s[i];
            else if (s[i] == ' ') {
                while (index < maxlength) {
                    result[index++] += " ";
                }
                index = 0;
            }
        }

        for (int i = 0; i < maxlength; i++) {
            auto it = find_if(result[i].rbegin(), result[i].rend(), [](char c) {return !isspace(c); }).base();
            result[i].erase(it, result[i].end());
        }
        return result;

    }
};