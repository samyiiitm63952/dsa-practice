class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
              vector<int> hash(256,0);
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1) break;
                hash[s[j]]++;
                 maxi=max(maxi,j-i+1);
            }
           
        }
        return maxi;
    }
};