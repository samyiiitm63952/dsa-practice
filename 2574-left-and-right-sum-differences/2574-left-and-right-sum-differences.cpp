class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>rightSum(n,0);
        vector<int>leftSum(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            leftSum[i] = sum;
            sum+=nums[i];
        }
        int rsum=0;
        for(int i=n-1;i>=0;i--){
            rightSum[i]=rsum;
            rsum+=nums[i];
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=abs(leftSum[i]-rightSum[i]);
        }
        return ans;
    }
};