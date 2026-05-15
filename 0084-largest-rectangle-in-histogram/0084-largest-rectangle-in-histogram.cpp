class Solution {
public:
    vector<int>PSE(vector<int>nums){
        vector<int>ans(nums.size(),-1);
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
                ans[i]= st.empty()?-1:st.top();
            }
          
            ans[i]= st.empty()?-1:st.top();
            st.push(i);
        }
        
        return ans;
    }
    vector<int>NSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st; // stores indices

    for (int i = n - 1; i >= 0; i--) {

        // remove elements > current
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        // if no smaller element exists
        nse[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    return nse;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse=NSE(heights);
        vector<int>pse=PSE(heights);
        int maxarea=0;
        for(int i=0;i<heights.size();i++){
            int area=heights[i]*(nse[i]-pse[i]-1);
            maxarea =max(maxarea,area);
        }
        return maxarea;
    }
};