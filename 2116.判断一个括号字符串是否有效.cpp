#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size(); // 获取字符串 s 的长度
        if (n % 2 != 0) return false; // 如果长度为奇数，直接返回 false

        // 从左到右遍历：检查可能的平衡
        int low = 0, high = 0; // low 表示最小可能的左括号数量，high 表示最大可能的左括号数量
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') { // 如果当前字符是锁定的
                if (s[i] == '(') {
                    low++; // 左括号增加
                    high++; // 左括号增加
                } else {
                    low--; // 右括号减少
                    high--; // 右括号减少
                }
            } else { // 如果当前字符是可变的
                low--; // 假设将其视为右括号
                high++; // 假设将其视为左括号
            }
            // 如果 high < 0，说明即使是最大可能的平衡也是无效的
            if (high < 0) return false;
            // 平衡不能为负数，所以调整 low
            low = max(low, 0); // 确保 low 不小于 0
        }
        // 处理完所有字符后，检查是否可能达到平衡为 0
        if (low > 0 || high < 0) return false; // 如果 low > 0，说明还有多余的左括号；如果 high < 0，说明右括号过多

        // 从右到左遍历：检查反向情况
        low = 0, high = 0; // 重置 low 和 high
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') { // 如果当前字符是锁定的
                if (s[i] == ')') {
                    low++; // 右括号增加
                    high++; // 右括号增加
                } else {
                    low--; // 左括号减少
                    high--; // 左括号减少
                }
            } else { // 如果当前字符是可变的
                low--; // 假设将其视为左括号
                high++; // 假设将其视为右括号
            }
            if (high < 0) return false; // 如果 high < 0，说明即使是最大可能的平衡也是无效的
            low = max(low, 0); // 确保 low 不小于 0
        }
        if (low > 0 || high < 0) return false; // 检查是否可能达到平衡为 0

        return true; // 如果通过了所有检查，返回 true
    }
};