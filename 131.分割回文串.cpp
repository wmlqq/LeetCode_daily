#include<vector>
#include<string>
using namespace std;
class Solution {
    private:
        void dfs(vector<vector<bool>>&dp,string&s,int start,vector<string>&temp,vector<vector<string>>&result){
            if(start>s.size()){
                return;
            }
            if(start==s.size()){
                result.push_back(temp);
                return;
            }
            for(int i=start;i<s.size();i++){
                if(dp[start][i]){
                    temp.push_back(s.substr(start,i-start+1));
                    dfs(dp,s,i+1,temp,result);
                    temp.pop_back();
                }
                else{
                    continue;
                }
            }
        }

    public:
        vector<vector<string>> partition(string s) {
            vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));//dp[i][j]表示s[i]到s[j]是否是回文串
            vector<vector<string>>result;
            for(int i=0;i<s.size();i++){
                for(int j=0;j<=i;j++){
                    if(s[i]==s[j]&&(i-j<2||dp[j+1][i-1])){
                        dp[j][i]=true;
                    }
                }
            }
                vector<string>temp;
                dfs(dp,s,0,temp,result);
            return result;
        }
    };