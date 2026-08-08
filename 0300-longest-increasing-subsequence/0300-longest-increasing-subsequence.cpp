class Solution {
public:
    int solveUsingMem(vector<int>&arr,int curr,int prev,vector<vector<int>>&dp){
        //base case
        if(curr>=arr.size()){
            return 0;
        }
        //include-exclude

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }

        int include=0;
        if(prev==-1|| arr[curr]>arr[prev]){
            include=1+solveUsingMem(arr,curr+1,curr,dp);
        }
         
        int exclude=0+solveUsingMem(arr,curr+1,prev,dp);
        int final=max(include,exclude);
        dp[curr][prev+1]=final;
        return final;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int prev=-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solveUsingMem(nums,curr,prev,dp);
        return ans;
    }
};