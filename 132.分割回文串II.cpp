#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
        int minCut(string s) {
            vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));//dp[i][j]表示s[i]到s[j]是否是回文串
            for(int i=0;i<s.size();i++){
                for(int j=0;j<=i;j++){
                    if(s[i]==s[j]&&(i-j<2||dp[j+1][i-1])){
                        dp[j][i]=true;
                    }
                    else continue;
                }
            }
            vector<int>cut(s.size(),0);//cut[i]表示s[0]到s[i]的最小切割次数
            for(int i=0;i<s.size();i++){
                if(dp[0][i]){
                    cut[i]=0;
                }
                else{
                    cut[i]=i;
                    for(int j=1;j<=i;j++){
                        if(dp[j][i]){
                            cut[i]=min(cut[i],cut[j-1]+1);
                        }
                    }
                }
            }
            return cut[s.size()-1];
        }
    };