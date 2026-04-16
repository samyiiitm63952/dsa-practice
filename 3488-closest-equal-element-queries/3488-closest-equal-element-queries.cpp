class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: map value -> indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for (int q : queries) {
            int val = nums[q];
            auto &v = mp[val];
            
            // If only one occurrence
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // Find position of q
            auto it = lower_bound(v.begin(), v.end(), q);
            int idx = it - v.begin();
            
            int res = INT_MAX;
            
            // Previous index (circular)
            int prev = v[(idx - 1 + v.size()) % v.size()];
            int d1 = abs(prev - q);
            res = min(res, min(d1, n - d1));
            
            // Next index (circular)
            int next = v[(idx + 1) % v.size()];
            int d2 = abs(next - q);
            res = min(res, min(d2, n - d2));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};