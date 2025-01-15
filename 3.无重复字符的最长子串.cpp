#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>check;
        int left = 0;
        int maxlength = 0;

        //采用滑动窗口的方法优化时间复杂度到O(n)
        for (int right = 0; right < s.length(); right++) {
            //如果右界已存在，则移动左界
            while (check.find(s.at(right)) != check.end()) {
                check.erase(s.at(left));
                left++;
            }
            check.insert(s.at(right));
            maxlength = max(maxlength, right - left + 1);
        }
        return maxlength;
    }
};