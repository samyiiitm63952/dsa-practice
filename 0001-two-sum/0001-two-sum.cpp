class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int k=nums[i]+nums[j];
                if(k==target)return{i,j};
            }
        }
        return {-1,-1};
    }
};