class Solution {
public:

    int findPeakElement(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        while(l < r) {

            int mid = l + (r - l) / 2;

            if(nums[mid] < nums[mid + 1]) {
                // increasing slope
                l = mid + 1;
            }
            else {
                // decreasing slope
                r = mid;
            }
        }

        return l;
    }
};