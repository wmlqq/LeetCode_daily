using namespace std;
#define NUMBERS 5
class Solution {
    public:
        int countVowelStrings(int n) {
            int sum=0;
            for(int i=1;i<=NUMBERS;i++)sum+=thenextchar(n-1,i);
            return sum;
        }

        int thenextchar(int n,int former){
            if(!n)return 1;
            int sum=0;
            for(int i=former;i<=NUMBERS;i++)sum+=thenextchar(n-1,i);
            return sum;
        }
    };