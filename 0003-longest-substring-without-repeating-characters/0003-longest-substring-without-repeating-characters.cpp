class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        vector<int>hash(256,0);
        int n=s.size();
        int maxlen=0;
        while(r<n && l<=r){
            if(hash[s[r]]==1){
                //duplicate found
                hash[s[l]] =0;
                l++;
            }
            else{
                hash[s[r]]=1;
                maxlen=max(maxlen,r-l+1);
                r++;
            
            }
            
        
       }
    
     return maxlen;}
};