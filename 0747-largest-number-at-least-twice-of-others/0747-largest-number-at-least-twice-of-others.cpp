class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=INT_MIN;
        int maxiIndex=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=maxi){
                maxi=nums[i];
                maxiIndex=i;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(i==maxiIndex)continue;
            if(!(nums[i]*2<=maxi)){
                return -1;
            }
        }
        return maxiIndex;
    }
};