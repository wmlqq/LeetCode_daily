#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        vector<string> shortestSubstrings(vector<string>& arr) {
            int n=arr.size();
            vector<string>result(n);
            for(int i=0;i<n;i++){
                string shortest="";
                for(size_t len=1;len<=arr[i].length();len++){

                    for(size_t start=0;start<=arr[i].length()-len;start++){
                        string substr=arr[i].substr(start,len);
                        
                        bool isfound=false;
                        for(int j=0;j<n;j++){
                            if(j!=i&&arr[j].find(substr)!=string::npos){
                                isfound=true;
                                break;
                            }
                        }
                        if(!isfound){
                            if(shortest==""||shortest.length()>substr.length()||(shortest.length()==substr.length()&&shortest>substr)){
                                shortest=substr;
                            }
                        }
                    }
                }
                result[i]=shortest;
            }
            return result;
        }
    };