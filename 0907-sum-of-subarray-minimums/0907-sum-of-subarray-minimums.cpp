class Solution {
public:
    vector<int>NSE(vector<int> arr){
            vector<int>ans(arr.size(),arr.size());
            stack<int>st;
            for(int i=arr.size()-1;i>=0;i--){
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                ans[i] = st.empty() ? arr.size() : st.top();
                st.push(i);
            }
            return ans;
        }

    vector<int>PSE(vector<int>arr){
        vector<int>ans(arr.size(),-1);
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i] )
            st.pop();

           ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>NSEs=NSE(arr);
        vector<int>PSEs=PSE(arr);
        long long total=0;
        int Mod=(int)(1e9+7);
        for(int i=0;i<arr.size();i++){
            long long left=NSEs[i]-i;
            long long right=i-PSEs[i];
            total += left*right*arr[i];
        }
        return total%Mod;
    }
};