class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        
        // Collect indices for each number
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // Check each number's index list
        for (auto &p : positions) {
            auto &indices = p.second;
            if (indices.size() >= 3) {
                // Only need to check consecutive triples
                for (int i = 0; i + 2 < indices.size(); i++) {
                    int dist = 2 * (indices[i+2] - indices[i]);
                    ans = min(ans, dist);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};