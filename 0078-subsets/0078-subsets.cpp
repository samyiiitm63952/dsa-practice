class Solution {
public:
   void solve(vector<vector<int>> &ans ,vector<int> &curr,vector<int>nums,int ind){
        if(ind == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        solve(ans,curr,nums,ind+1);
        curr.pop_back();
        solve(ans,curr,nums,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int ind=0;
        solve(ans,curr,nums,ind);
        return ans;
    }
};