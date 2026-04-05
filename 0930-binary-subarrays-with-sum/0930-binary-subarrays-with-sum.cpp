class Solution {
public:
    int cnt(vector<int> &nums,int goal){
        if(goal <0){return 0;}
        int l=0;
        int r=0;
        int cnts=0;
        int sum=0;
        while(r<nums.size()){
            sum +=nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            cnts=cnts+(r-l+1);
            r++;
        }
        return cnts;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return cnt(nums,goal)-cnt(nums,goal-1);
    }
};