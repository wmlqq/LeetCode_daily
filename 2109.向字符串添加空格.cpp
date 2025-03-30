#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        string addSpaces(string s, vector<int>& spaces) {
            if(spaces.size()==0)return s;
            int index=0;
            string res;
            for(int i=0;i<s.length();i++){
                if(index<spaces.size()&&i==spaces[index]){res.push_back(' ');index++;}
                res.push_back(s[i]);
            }
            return res;
        }
    };