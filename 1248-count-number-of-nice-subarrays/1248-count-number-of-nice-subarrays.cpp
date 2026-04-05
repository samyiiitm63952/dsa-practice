class Solution {
public:
  int cnt(vector<int> &nums,int goal){
        if(goal <0){return 0;}
        int l=0;
        int r=0;
        int cnts=0;
        int sum=0;
        while(r<nums.size()){
            sum +=nums[r]%2;
            while(sum>goal){
                sum -= nums[l]%2;
                l++;
            }
            cnts=cnts+(r-l+1);
            r++;
        }
        return cnts;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cnt(nums,k)- cnt(nums,k-1);
        }
};