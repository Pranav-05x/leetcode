class Solution {
public:
    long long countCommas(long long n) {
        long ans=0;
        long limit=1000;
        while(n>=limit){
            ans+=(n-limit)+1;
            limit*=1000;
        }
        return ans;
    }
};