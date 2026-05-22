class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){

            int m = l + (r - l)/2;

            if(nums[m] == target)
                return m;

            // Left half sorted
            if(nums[l] <= nums[m]){

                // Target inside left half
                if(target >= nums[l] && target < nums[m]){
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }

            // Right half sorted
            else{

                // Target inside right half
                if(target > nums[m] && target <= nums[r]){
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};