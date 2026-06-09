class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return 1LL* k*(nums[nums.size()-1]-nums[0]);
    }
};