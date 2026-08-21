class Solution {
public:
    void find(unordered_map<int,int>&mp,int&k,vector<int>&ans){
        if(k==0){
            return;
        }
        int maxi=0;
        int element=0;
        for(auto it:mp){
            if(it.second>maxi){
                maxi=it.second;
                element=it.first;
            }
        }
        ans.push_back(element);
        mp.erase(element);
        k--;
        find(mp,k,ans);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       vector<int>ans;
       for(int i=0;i<nums.size();i++){
          mp[nums[i]]++;
       }
      
      find(mp,k,ans);
       return ans;
    }
};