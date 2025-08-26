class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
int n = grid.size();
if(grid[0][0] == 1) return -1;
queue<pair<int,pair<int,int>>>q;
//vector<vector>vis(n,vector(n,INT_MAX));
vector<vector<int>> vis(n, vector<int>(n, INT_MAX));
q.push({1,{0,0}});
vis[0][0] = 1;
while(!q.empty()){
int dist = q.front().first;
int row = q.front().second.first;
int col = q.front().second.second;
q.pop();

        for(int i = -1; i<=1; i++){
            for(int j = -1; j<=1; j++){
                if (i == 0 && j == 0) continue;

                int nrow = row + i;
                int ncol = col + j;

                if(nrow >= 0 && nrow<n && ncol >= 0 && ncol<n && grid[nrow][ncol] == 0 && vis[nrow][ncol] > dist + 1){
                    vis[nrow][ncol] = dist + 1;
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }
    }
    if(vis[n-1][n-1] == INT_MAX) return -1;
    else return vis[n-1][n-1];
}
};

