class Solution {
public:
    void solve(set<vector<int>>& st,vector<int> nums,int idx){
        if(idx==nums.size()){
            st.insert(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            solve(st,nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        solve(st,nums,0);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;

    }
};