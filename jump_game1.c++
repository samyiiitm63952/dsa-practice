class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindex=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxindex) return false;
            maxindex=max(maxindex,i+nums[i]);
        }
        if(maxindex>=nums.size()-1){
            return true;
        }
        else{
            return false;
        }
    }
};