class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int j=0;i<g.size() && j<s.size();j++){
            if(s[j]>=g[i]){
                i++;
            }
            else{
                continue;
            }
    
     }   
    
     return i;  }
};