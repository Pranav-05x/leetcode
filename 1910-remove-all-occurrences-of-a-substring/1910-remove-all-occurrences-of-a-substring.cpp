class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        for(int i=0;i<s.length();i++){
            ans+=s[i];
            if(ans.size()>=part.size()){
                string str=ans.substr(ans.size()-part.size(),part.size());
                if(str==part){
                    ans.erase(ans.size()-part.size(),part.size());
                }
            }
        }
        return ans;
    }
};