class Solution {
public:

    void solve(int open,
               int close,
               string &curr,
               vector<string>& ans,
               int n){

        // complete valid string
        if(curr.size() == 2*n){

            ans.push_back(curr);
            return;
        }

        // add opening bracket
        if(open < n){

            curr.push_back('(');

            solve(open + 1,
                  close,
                  curr,
                  ans,
                  n);

            curr.pop_back();
        }

        // add closing bracket
        if(close < open){

            curr.push_back(')');

            solve(open,
                  close + 1,
                  curr,
                  ans,
                  n);

            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        string curr;

        solve(0,0,curr,ans,n);

        return ans;
    }
};