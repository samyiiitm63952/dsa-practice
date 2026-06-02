class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i=0;
        int cnt=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]==0){
                if(nums[j]!=0){
                    swap(nums[i],nums[j]);
                i++;
                j--;
                cnt++;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};