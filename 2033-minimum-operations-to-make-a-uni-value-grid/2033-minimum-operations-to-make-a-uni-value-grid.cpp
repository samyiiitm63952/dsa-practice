class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
        // Flatten
        for (auto &row : grid) {
            for (auto &val : row) {
                arr.push_back(val);
            }
        }
        
        // Check feasibility
        int mod = arr[0] % x;
        for (int v : arr) {
            if (v % x != mod) return -1;
        }
        
        // Sort
        sort(arr.begin(), arr.end());
        
        // Median
        int median = arr[arr.size()/2];
        
        // Count operations
        int ops = 0;
        for (int v : arr) {
            ops += abs(v - median) / x;
        }
        
        return ops;
    }
};