#include<string>
using namespace std;
class Solution {
    public:
        string breakPalindrome(string palindrome) {
            if(palindrome.size()<=1)return ""; 
            if(palindrome.size()%2==0){
                for(char&c:palindrome){
                    if(c!='a'){
                        c='a';
                        return palindrome;
                    }
                }
            }
            else{
                for(int i=0;i<palindrome.size()-1;i++){
                    if(palindrome[i]!='a'){
                        if(i!=(palindrome.size()-1)/2){
                            palindrome[i]='a';
                            return palindrome;
                        }
                        else continue;
                    }
                }
            }
            return palindrome.substr(0,palindrome.size()-1)+'b';
        }
    };