class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
         int ans=0;

        for(int ch='a';ch<='z';ch++){
            bool lower=false;
            bool upper=false;

           for(char c:word) {
                if(c==ch)
                    lower=true;

                if(c==ch-32)
                    upper = true;
            }
            if(upper&&lower)ans++;
        }
        return ans;
    }
};