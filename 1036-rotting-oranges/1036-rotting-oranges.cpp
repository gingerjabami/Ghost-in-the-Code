class Solution {
public:
    void bfs(int i,int j,int timer,vector<vector<int>>& grid,queue<pair<pair<int,int>,int>> &q ){
        if(i>0 && grid[i-1][j]==1){
            q.push({{i-1,j},timer+1}) ;
            grid[i-1][j]=2 ;
        }
        if(j<grid[0].size()-1 && grid[i][j+1]==1){
            q.push({{i,j+1},timer+1}) ;
            grid[i][j+1]=2 ;
        }
        if(i<grid.size()-1 && grid[i+1][j]==1){
            q.push({{i+1,j},timer+1}) ;
            grid[i+1][j]=2 ;
        }
        if(j>0 && grid[i][j-1]==1){
            q.push({{i,j-1},timer+1}) ;
            grid[i][j-1]=2 ;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q ;
        for(int i=0 ;i<grid.size();i++){
            for(int j=0 ;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}) ;
                }
            }
        }
    if(q.empty()) {
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 1)
             return -1; 
        }
    }
    return 0;
   }
        int timer=-1 ;
        while(!q.empty()){
           auto front =  q.front() ;
           timer = front.second ;
           q.pop() ;
           bfs(front.first.first,front.first.second,front.second,grid,q) ;
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return timer ;
    }
};