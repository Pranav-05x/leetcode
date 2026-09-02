class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int maxi=0;
        int n=citations.size();
        for(int h=1;h<=citations[n-1];h++){
            int count=0;
            for(int i=0;i<n;i++){
                if(citations[i]>=h){
                    count++;
                }
                if(count>=h){
                  maxi=max(maxi,h);
                  break;
                }
            }
            
        }
        return maxi;
    }
};