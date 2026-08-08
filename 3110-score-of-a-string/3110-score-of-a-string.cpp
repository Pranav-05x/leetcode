class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=0;i+1<s.length();i++){
            char ch1=s[i];
            char ch2=s[i+1];
            ans=ans+abs(int(ch2)-int(ch1));
        }
        return ans;
    }
};