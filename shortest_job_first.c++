class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        int wtime=0;
        int currtime=0;
        for(int i=0;i<bt.size();i++){
            wtime += currtime;
            currtime += bt[i];
        }
        return wtime/bt.size();
    }
};