#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> evenOddBit(int n) {
            vector<int> result(2,0);
            for(int i=0;n>0;i++,n>>=1){
                if(n&1){
                    result[i%2]++;
                }
            }
            return result;
        }
    };