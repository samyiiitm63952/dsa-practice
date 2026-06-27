class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special handling for 1
        if (freq.count(1)) {
            int ones = freq[1];
            ans = max(ans, (ones % 2 == 1 ? ones : ones - 1));
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 1;   // single element always possible

            while (freq[cur] >= 2) {
                long long nxt = cur * cur;

                if (nxt > 1e18 || !freq.count(nxt))
                    break;

                len += 2;
                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};