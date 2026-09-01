class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(to_string(nums[i]));
        }

        sort(arr.begin(),arr.end(),[](string a,string b){
            return a+b>b+a;
        });
        string ans="";
        for(auto it:arr){
            ans+=it;
        }
        if(arr[0]=="0"){
            return "0";
        }
        return ans;
    }
};