class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int mins=INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]==nums[k] && nums[k]==nums[j]){
                        mins=min(mins,abs(i - j) + abs(j - k) + abs(k - i));
                    }
                }
            }
        }
    return mins==INT_MAX?-1:mins;
    }
};