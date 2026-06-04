class Solution {
public:

    void solve(string &curr,
               vector<string>& ans,
               string &digits,
               vector<string>& keypad,
               int idx){

        // complete combination formed
        if(idx == digits.size()){

            ans.push_back(curr);
            return;
        }

        // current digit
        string letters = keypad[digits[idx] - '0'];

        // try all letters
        for(char ch : letters){

            curr.push_back(ch);

            solve(curr,
                  ans,
                  digits,
                  keypad,
                  idx + 1);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.empty()) return ans;

        vector<string> keypad = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        string curr = "";

        solve(curr, ans, digits, keypad, 0);

        return ans;
    }
};