#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
        int minimizedStringLength(string s) {
         vector<char>ex;
         int res=0;
         for(char&c:s){
            if(find(ex.begin(),ex.end(),c)!=ex.end())continue;
            res++;
            ex.push_back(c);
         }
         return res;
        }
    };