class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans(nums1.size(), -1);

        for(int i=0;i<nums1.size();i++){

            stack<int> st;

            for(int j=0;j<nums2.size();j++){

                if(nums1[i]==nums2[j]){

                    for(int k=nums2.size()-1;k>j;k--){
                        st.push(nums2[k]);
                    }

                    while(!st.empty() && st.top() < nums2[j]){
                        st.pop();
                    }

                    if(!st.empty())
                        ans[i]=st.top();

                    break;
                }
            }
        }

        return ans;
    }
};