class Solution {
public:

    void solve(int index,
               vector<int>& candidates,
               int target,
               vector<int>& temp,
               set<vector<int>>& st){

        if(target == 0){

            st.insert(temp);

            return;
        }
       

        if(index >= candidates.size())
            return;

        for(int i = index; i < candidates.size(); i++){

            if(i > index &&
   candidates[i] == candidates[i-1])
    continue;
            if(candidates[i] <= target){

                temp.push_back(candidates[i]);

                solve(i+1,
                      candidates,
                      target - candidates[i],
                      temp,
                      st);

                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(),
             candidates.end());

        set<vector<int>> st;

        vector<int> temp;

        solve(0,
              candidates,
              target,
              temp,
              st);

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};