class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>roman_map={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans=0;
        for(int i=0;i<s.length();i++){
           if(i+1<s.length()&&roman_map[s[i]]<roman_map[s[i+1]]){
             ans-=roman_map[s[i]];
           }else{
             ans+=roman_map[s[i]];
           }
        }
        return ans;
    }
};