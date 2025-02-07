#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 初始化 n x n 矩阵
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        // 定义边界
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int num = 1;  // 从 1 开始填充
        
        while (left <= right && top <= bottom) {
            // 从左到右填充上边
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++;
            
            // 从上到下填充右边
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--;
            
            if (top <= bottom) {
                // 从右到左填充下边
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }
            
            if (left <= right) {
                // 从下到上填充左边
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};