class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            while(nums[i]){
                int digit =nums[i]%10;
                nums[i]=nums[i]/10;
                sum +=digit;
                
            }
            mini =min(mini,sum);
        }
        return mini;
    }
};