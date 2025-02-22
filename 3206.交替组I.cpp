#include<vector>
using namespace std;
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors) {
            int result=0;
            for(int i=0;i<colors.size();i++){
                if(colors[i]==colors[(i+2)%colors.size()]&&colors[i]!=colors[(i+1)%colors.size()])result++;
                }
            return result;
        }
    };