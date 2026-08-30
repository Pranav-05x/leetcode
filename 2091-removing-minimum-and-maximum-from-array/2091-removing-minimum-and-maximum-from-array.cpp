class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIndex=0;
        int minIndex=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
                minIndex=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                maxIndex=i;
            }
        }
        
        int l=min(minIndex,maxIndex);
        int r=max(minIndex,maxIndex);
        int n=nums.size();
        
        int front=r+1;
        int back=n-l;
        int both=(l+1)+(n-r);
        
        int ans=min(front,min(back,both));
        return ans;
    }
};