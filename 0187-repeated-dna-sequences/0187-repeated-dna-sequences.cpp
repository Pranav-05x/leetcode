class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=0,r=l+9;
        unordered_map<string,int>mp;
        vector<string>ans;
        while(r<s.size()){
            string str="";
            for(int i=l;i<=r;i++){
                str.push_back(s[i]);
            }
            mp[str]++;
            if(mp.find(str)!=mp.end()){
                if(mp[str]==2){
                 ans.push_back(str);
                }
            }
            l++;
            r=l+9;
        }
        return ans;
    }
};