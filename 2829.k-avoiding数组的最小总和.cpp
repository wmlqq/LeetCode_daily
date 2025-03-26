class Solution {
    public:
        int minimumSum(int n, int k) {
            int half=k/2;
            int res=(n>half)? half*(half+1)/2:n*(n+1)/2;
            int count=n-half;
            while(count-->0)res+=(k++);
            return res;
        }
    };