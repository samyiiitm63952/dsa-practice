class Solution {
public:
    void solver(vector<int>& candi,vector<int>& curr,vector<vector<int>>& ans,int target,int n,int i ){
        if(i>=n){
            if(target == 0)ans.push_back(curr);
            return;
        }
        if(target>=candi[i]){
            curr.push_back(candi[i]);
            solver(candi,curr,ans,target-candi[i],n,i);
            curr.pop_back();
        }
        solver(candi,curr,ans,target,n,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n=candidates.size();
        solver(candidates,curr,ans,target,n,0);
        return ans;
    }
};