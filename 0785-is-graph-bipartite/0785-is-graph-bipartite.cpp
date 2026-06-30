class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int start,
             int colori) {
        color[start] = colori;
        for (auto nei : graph[start]) {
            if (color[nei] == -1) {
                if (!dfs(graph, color, nei, !colori))
                    return false;
            }

            else if (color[nei] == color[start]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < color.size(); i++) {
            if (color[i] == -1) {
                if(!dfs(graph, color,i, 0))return false;
            }
        }
        return true;
    }
};