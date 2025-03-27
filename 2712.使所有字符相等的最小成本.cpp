#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        long long minimumCost(string s) {
            vector<vector<long long>>dpfront(s.length(),vector<long long>(2,0));
            vector<vector<long long>>dprear(s.length(),vector<long long>(2,0));
            if(s[0]=='0'){
                dpfront[0][0]=0;
                dpfront[0][1]=1;
            }
            if(s[0]=='1'){
                dpfront[0][0]=1;
                dpfront[0][1]=0;
            }
            if(s[s.length()-1]=='0'){
            dprear[s.length()-1][0]=0;
            dprear[s.length()-1][1]=1;
            }
            if(s[s.length()-1]=='1'){
            dprear[s.length()-1][0]=1;
            dprear[s.length()-1][1]=0;
            }

            for(int i=1;i<s.length();i++){
                if(s[i]=='0'){
                    dpfront[i][0]=dpfront[i-1][0];
                    dpfront[i][1]=dpfront[i-1][0]+i+1;
                }
                if(s[i]=='1'){
                    dpfront[i][1]=dpfront[i-1][1];
                    dpfront[i][0]=dpfront[i-1][1]+i+1;
                }
            }

            for(int i=s.length()-2;i>=0;i--){
                if(s[i]=='0'){
                    dprear[i][0]=dprear[i+1][0];
                    dprear[i][1]=dprear[i+1][0]+s.length()-i;
                }
                if(s[i]=='1'){
                    dprear[i][1]=dprear[i+1][1];
                    dprear[i][0]=dprear[i+1][1]+s.length()-i;
                }
            }

            long long res=LONG_LONG_MAX;
            for(int i=0;i<s.length();i++)res=min(res,min(dpfront[i][0]+dprear[i][0],dpfront[i][1]+dprear[i][1]));
            return res;
        }
    };