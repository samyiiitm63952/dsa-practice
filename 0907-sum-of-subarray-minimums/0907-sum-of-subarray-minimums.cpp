class Solution {
public:

    vector<int> pse(vector<int>& arr) {

        int n = arr.size();

        vector<int> left(n);

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return left;
    }

    vector<int> nse(vector<int>& arr) {

        int n = arr.size();

        vector<int> right(n);

        stack<int> st;

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return right;
    }

    int sumSubarrayMins(vector<int>& arr) {

        const int MOD = 1e9 + 7;

        int n = arr.size();

        vector<int> left = pse(arr);
        vector<int> right = nse(arr);

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long leftCount = i - left[i];

            long long rightCount = right[i] - i;

            long long contribution =
                (1LL * arr[i] * leftCount * rightCount);

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};