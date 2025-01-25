#include<vector>
#define Sidelength 8
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int Ri=-1, Rj=-1;
        for (int i = 0; (i < Sidelength) && (Ri == -1); i++) {
            for (int j = 0; j < Sidelength; j++) {
                if (board[i][j] == 'R') {
                    Ri = i; Rj = j; break;
                }
            }
        }
        int result = 0;

        //向上寻找
        for (int i = Ri-1, j = Rj; i >= 0; i--) {
            if (board[i][j] == 'p') {
                result++; break;
            }
            else if (board[i][j] == 'B')break;
        }

        //向下寻找
        for (int i = Ri+1, j = Rj; i<Sidelength; i++) {
            if (board[i][j] == 'p') {
                result++; break;
            }
            else if (board[i][j] == 'B')break;
        }

        //向左寻找
        for (int i = Ri, j = Rj-1; j >= 0; j--) {
            if (board[i][j] == 'p') {
                result++; break;
            }
            else if (board[i][j] == 'B')break;
        }

        //向右寻找
        for (int i = Ri, j = Rj + 1; j<Sidelength; j++) {
            if (board[i][j] == 'p') {
                result++; break;
            }
            else if (board[i][j] == 'B')break;
        }

        return result;
    }
};