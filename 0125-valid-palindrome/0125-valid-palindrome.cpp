class Solution {
public:
    bool helper(string &temp,int n,int i){
        if(i>=n/2)return true;
        if(temp[i]!=temp[n-i-1]){
            return false;
        }
        return helper(temp,n,i+1);
    }
    bool isPalindrome(string s) {
        string temp = "";
        for(auto it:s){
            if((it>='a'&& it<='z') ||( it>='A' && it<='Z') ||(it>='0'&& it<='9')){
                 temp += toupper(it);
            }   
        }
        int n=temp.size();
        int i=0;
        return helper(temp,n,i);

    }
};