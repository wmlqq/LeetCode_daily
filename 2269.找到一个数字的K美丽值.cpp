class Solution {
    public:
        int divisorSubstrings(int num, int k) {
            int count=0,newnum=num;
            while(newnum>0){
                count++;
                newnum/=10;
            }
            int front=count,rear=count-k;
            long long divfront=1,divrear=1;
            for(int i=0;i<count;i++){
                if(i<rear){
                    divrear*=10;
                }
                divfront*=10;
            }

            count=0;
            while(divrear>0){
                long long res=num%divfront;
                res=res/divrear;
                if(res!=0&&num%res==0){
                    count++;
                }
                divfront/=10;
                divrear/=10;
            }
            return count;
        }
    };