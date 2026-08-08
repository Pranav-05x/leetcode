class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        if(mp.size()==1)return true;
        
        int freq=mp[s[0]];
        for(auto it:mp){
            if(it.second!=freq)return false;
        }
        return true;
    }
};