#include<string>
using namespace std;
class Solution {
    public:
        int percentageLetter(string s, char letter) {
            int res=0;
            for(auto c:s){
                if(c==letter)res++;
            }
            return res*100/s.length();
        }
    };