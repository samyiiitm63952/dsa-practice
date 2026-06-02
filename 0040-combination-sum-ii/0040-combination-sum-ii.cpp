class Solution {
public:
    void solver(vector<int>& curr,vector<int>& candii,int target,vector<vector<int>>& ans,int idx){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<candii.size();i++){
            if(i>idx && candii[i]== candii[i-1]){
                continue;
            }
            if(candii[i]>target){
                break;
            }
            curr.push_back(candii[i]);
            solver(curr,candii,target-candii[i],ans,i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        solver(curr,candidates,target,ans,0);
        return ans;
    }
};