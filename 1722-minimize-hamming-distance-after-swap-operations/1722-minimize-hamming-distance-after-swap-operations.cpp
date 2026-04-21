class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb)
            parent[pa] = pb;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // initialize DSU
        for (int i = 0; i < n; i++) parent[i] = i;

        // Step 1: union
        for (auto &p : allowedSwaps) {
            unite(p[0], p[1]);
        }

        // Step 2: group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        // Step 3: calculate mismatches
        int ans = 0;

        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // count source values
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // match with target
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};