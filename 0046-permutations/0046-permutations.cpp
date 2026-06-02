class Solution {
public:
    void solver(vector<vector<int>>& ans,vector<int>& curr ,vector<int>nums,vector<bool>& mpp ){
        if(curr.size()>=nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[i]==true)continue;
            mpp[i]=true;
            curr.push_back(nums[i]);
            solver(ans,curr,nums,mpp);
            mpp[i]=false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        vector<bool>mpp(nums.size(),false);
        solver(ans,curr,nums,mpp);
        return ans;
    }
};