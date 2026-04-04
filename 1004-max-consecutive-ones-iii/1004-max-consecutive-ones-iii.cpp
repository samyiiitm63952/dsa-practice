class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        int l = 0, r = 0;
        int zero = 0;

        while (r < nums.size()) {

            // 1. include current element
            if (nums[r] == 0) zero++;

            // 2. shrink if invalid
            while (zero > k) {
                if (nums[l] == 0) zero--;
                l++;
            }

            // 3. update answer
            maxlen = max(maxlen, r - l + 1);

            // 4. move right
            r++;
        }

        return maxlen;
    }
};