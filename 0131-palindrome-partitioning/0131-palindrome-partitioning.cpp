class Solution {
public:

    bool ispali(string s){

        int left = 0;
        int right = s.size()-1;

        while(left < right){

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(string s,
               int idx,
               vector<vector<string>>& ans,
               vector<string>& curr){

        // partition complete
        if(idx >= s.size()){

            ans.push_back(curr);
            return;
        }

        // generate substrings
        for(int i=idx; i<s.size(); i++){

            string part = s.substr(idx, i-idx+1);

            // if palindrome
            if(ispali(part)){

                curr.push_back(part);

                solve(s, i+1, ans, curr);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;

        vector<string> curr;

        solve(s, 0, ans, curr);

        return ans;
    }
};