class Solution {
public:
    void solver(set<vector<int>>& st, vector<int>& curr,vector<int> nums,int i){
        if(i>=nums.size()){
            vector<int>temp(curr.begin(),curr.end());
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        curr.push_back(nums[i]);
        solver(st,curr,nums,i+1);
        curr.pop_back();
        solver(st,curr,nums,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        set<vector<int>>st;
        solver(st,curr,nums,0);
        vector<vector<int>>ans (st.begin(),st.end());
        return ans;
    }
};