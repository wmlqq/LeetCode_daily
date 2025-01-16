#include <vector>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // 处理特殊情况
        if (numRows == 1 || s.length() <= numRows) return s;

        int n = s.length();
        vector<string> rows(numRows);

        // 使用字符串数组代替二维vector，避免复杂的索引计算
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        // 合并所有行
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};