#include<string>
#include<vector>
#include<set>
using namespace std;
class Solution {
    public:
        int similarPairs(vector<string>& words) {
            int result=0;
            for(int i=0;i<words.size();i++){
                for(int j=i+1;j<words.size();j++){
                    if(isSimilar(words[i],words[j])){
                        result++;
                    }
                }
        }
        return result;
    }
    
    bool isSimilar(string& a,string& b){
        set<char> setA;
        set<char> setB;
        for(auto& c:a){
            setA.insert(c);
        }
        for(auto& c:b){
            setB.insert(c);
        }
        if(setA==setB)return true;
        else return false;
    }
    };