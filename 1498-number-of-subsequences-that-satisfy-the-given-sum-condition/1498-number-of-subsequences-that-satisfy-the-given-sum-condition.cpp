class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());

        // Precompute powers of 2
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i-1] * 2LL) % mod;
        }

        int left = 0, right = n - 1;
        int cnt = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                cnt = (cnt + power[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }
        return cnt;
    }
};
