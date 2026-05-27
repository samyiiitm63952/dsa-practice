class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(auto it:s){
            if((it>='a'&& it<='z') ||( it>='A' && it<='Z') ||(it>='0'&& it<='9')){
                 temp += toupper(it);
            }
            
           
        }
        string str =temp;
        reverse(str.begin(),str.end());
        return (str==temp);

    }
};