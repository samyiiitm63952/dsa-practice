class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
     int i=start;
     int j=start;
     while(i>=0 || j<nums.size()){
        if(i>=0 && nums[i]==target){
            return abs(i-start);
        }
        else if(j<nums.size() &&nums[j]==target){
            return abs(j-start);
        }
        i--;
        j++;
     }   
    return -1;}
};