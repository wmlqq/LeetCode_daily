#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        int countPrefixes(vector<string>& words, string s) {
            int count=0;
            for(auto&word:words){
                if(s.find(word)==0)count++;
            }
            return count;
        }
    };