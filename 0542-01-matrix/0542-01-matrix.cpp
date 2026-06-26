class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>distance(n,vector<int>(m,0));
        int level = 0;
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},level});
                    vis[i][j]= true;
                    distance[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front().first;
            int curlevel = q.front().second;

            q.pop();

            for(int i =0;i<4;i++){
                int nrow= curr.first + delrow[i];
                int ncol = curr.second + delcol[i];

                if(nrow>=0 && nrow < n && ncol>= 0 && ncol <m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    distance[nrow][ncol]= curlevel+1;
                    q.push({{nrow,ncol},curlevel+1});
                }
            }

        }
        return distance;
    }
};