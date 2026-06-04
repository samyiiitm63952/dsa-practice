class Solution {
public:

    void solve(int idx, vector<string>& ans, string& curr, int n){

        if(idx == n){
            ans.push_back(curr);
            return;
        }

        // always place 1
        curr.push_back('1');
        solve(idx + 1, ans, curr, n);
        curr.pop_back();

        // place 0 only if allowed
        if(curr.empty() || curr.back() != '0'){
            curr.push_back('0');
            solve(idx + 1, ans, curr, n);
            curr.pop_back();
        }
    }

    vector<string> validStrings(int n) {

        vector<string> ans;
        string curr;

        solve(0, ans, curr, n);

        return ans;
    }
};