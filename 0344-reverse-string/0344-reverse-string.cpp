class Solution {
public:
    void helper(vector<char>&s,int i,int n){
        if(i>=n/2)return ;
        swap(s[i],s[n-i-1]);
        helper(s,i+1,n);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        helper(s,i,n);
    }
};