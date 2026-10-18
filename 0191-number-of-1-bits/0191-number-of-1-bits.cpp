class Solution {
public:
    int setBits(int n){
        vector<int>bits;
        int count=0;
        while(n>0){
            if(n%2==0){
                bits.push_back(0);
            }
            else{
                bits.push_back(1);
            }
            n=n/2;
        }
        for(int i=0;i<bits.size();i++){
            if(bits[i]==1)count++;
        }
        return count;
    }
    int hammingWeight(int n) {
        int count=setBits(n);
        return count;
    }
};