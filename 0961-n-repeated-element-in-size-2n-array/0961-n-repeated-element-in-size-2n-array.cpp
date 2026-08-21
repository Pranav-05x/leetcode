class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size()/2;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==n){
                ans=nums[i];
                break;
            }
        }
       return ans;
    }
};