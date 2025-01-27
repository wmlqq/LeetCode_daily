#include<vector>

using namespace std;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int downb = circles[0][1] - circles[0][2],
            upb = circles[0][1] + circles[0][2],
            leftb = circles[0][0] - circles[0][2],
            rightb = circles[0][0] + circles[0][2];
        int n = circles.size();
        for (int i = 0; i < n; i++) {
            downb = min(downb, circles[i][1] - circles[i][2]);
            upb = max(upb, circles[i][1] + circles[i][2]);
            leftb = min(leftb, circles[i][0] - circles[i][2]);
            rightb = max(rightb, circles[i][0] + circles[i][2]);
        }

        int result = 0;
        for (int i = leftb; i <= rightb; i++) {
            for (int j = downb; j <= upb; j++) {
                for (int k = 0; k < n; k++) {
                    if ((i - circles[k][0]) * (i - circles[k][0]) + (j - circles[k][1]) * (j - circles[k][1]) <= circles[k][2] * circles[k][2]) {
                        result++;
                        break;
                    }
                }
            }
        }
        return result;
    }
};