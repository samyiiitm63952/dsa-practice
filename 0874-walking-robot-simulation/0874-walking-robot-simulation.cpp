class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
         vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        
        int x = 0, y = 0, direction = 0;
        int maxDistance = 0;
        
        // Store obstacles in a hash set for O(1) lookup
        unordered_set<string> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        
        for (int cmd : commands) {
            if (cmd == -2) { // turn left
                direction = (direction + 3) % 4;
            } else if (cmd == -1) { // turn right
                direction = (direction + 1) % 4;
            } else { // move forward cmd steps
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    string pos = to_string(nx) + "," + to_string(ny);
                    
                    if (obstacleSet.find(pos) != obstacleSet.end()) {
                        break; // stop if obstacle
                    }
                     x = nx;
                    y = ny;
                    maxDistance = max(maxDistance, x*x + y*y);
                }
            }
        }
        
        return maxDistance;


    }
};