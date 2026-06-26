class Fenwick {
    vector<int> bit;
    int n;

public:
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
     long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto getIndex = [&](int x) {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        };

        Fenwick fw(vals.size());

        long long ans = 0;

        for (int x : pref) {
            int idx = getIndex(x);

            ans += fw.query(idx - 1);  
            fw.update(idx, 1);
        }

        return ans;
    }
};