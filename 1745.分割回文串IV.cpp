#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
        bool checkPartitioning(string s) {
            vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));//dp[i][j]表示s[i...j]是否是回文串
            for(int i=0;i<s.size();i++)dp[i][i]=true;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]==s[i+1])dp[i][i+1]=true;
            }
            for(int len=3;len<s.size()+1;len++){
                for(int i=0;i+len-1<s.size();i++){
                    int j=i+len-1;
                    if(s[i]==s[j]&&dp[i+1][j-1])dp[i][j]=true;
                }
            }
            for(int i=0;i<s.size();i++){
                for(int j=i+1;j<s.size()-1;j++){
                    if(dp[0][i]&&dp[i+1][j]&&dp[j+1][s.size()-1])return true;
                }
            }
            return false;
        }
    };