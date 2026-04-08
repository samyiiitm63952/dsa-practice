class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        int mod = 1e9 + 7;
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];
            int idx=l;
            while(idx<=r){
                long long temp=nums[idx];
                temp =(temp * v) % mod;
                nums[idx]=(int)temp;
                idx +=k;
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;
    }
};