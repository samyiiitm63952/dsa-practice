class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size() && j!=i;j++){
                int k=nums[i]+nums[j];
                if(k==target)return{i,j};
            }
        }
        return {-1,-1};
    }
};