class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for(int i = 0; i < num.size(); i++) {

            while(!st.empty() &&
                  k > 0 &&
                  st.top() > num[i]) {

                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // if k still remains
        while(k > 0) {
            st.pop();
            k--;
        }

        string ans(st.size(), ' ');

        for(int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        // remove leading zeros
        int i = 0;

        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if(ans == "") {
            return "0";
        }

        return ans;
    }
};