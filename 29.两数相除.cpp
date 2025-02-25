#include<cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 处理溢出情况
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // 溢出情况
        }
        
        // 处理除数为零的情况
        if (divisor == 0) {
            return INT_MAX; // 或者抛出异常
        }
        
        // 确定结果的符号
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // 使用 long long 避免溢出
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        
        long long quotient = 0;
        
        // 使用位运算进行除法
        while (absDividend >= absDivisor) {
            long long temp = absDivisor, multiple = 1;
            while (absDividend >= (temp << 1)) {
                temp <<= 1; // 将除数翻倍
                multiple <<= 1; // 将计数翻倍
            }
            absDividend -= temp; // 减去最大的倍数
            quotient += multiple; // 累加计数
        }
        
        // 根据符号返回结果
        return negative ? -quotient : quotient;
    }
};