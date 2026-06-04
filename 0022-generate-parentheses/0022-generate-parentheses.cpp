class Solution {
public:
    void solve(int open,int close, vector<string>& ans ,string curr,int n){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            open+=1;
            solve(open,close,ans,curr,n);
            curr.pop_back();
            open--;
        }
        if(close<open){
            curr.push_back(')');
            close+=1;
            solve(open,close,ans,curr,n);
            curr.pop_back();
            close--;
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        solve(0,0,ans,curr,n);
        return ans;
    }
};