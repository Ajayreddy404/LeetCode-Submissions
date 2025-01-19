class Solution {
public:

    void pushNodes(queue<pair<int,int>> &qu, pair<int,int> &p, vector<vector<int>> &grid){
        int i = p.first, j = p.second;
        // cout<<i<<" "<<j<<endl;
        if(i-1>=0 && grid[i-1][j]==1){
            grid[i-1][j] = 2;
            qu.push({i-1,j});
        }
        if(i+1<grid.size() && grid[i+1][j]==1){
            grid[i+1][j] = 2;
            qu.push({i+1,j});
        }  
        if(j-1>=0 && grid[i][j-1]==1){
            grid[i][j-1] = 2;
            qu.push({i,j-1});
        }
        if(j+1<grid[0].size() && grid[i][j+1]==1){
            grid[i][j+1] = 2;
            qu.push({i,j+1});
        }
        return;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int n = grid.size(), m = grid[0].size();
        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2)   qu.push({i,j});
                if(grid[i][j]==1)   flag = true;
            }
        }
        int time = 0;
        if(!flag)    return 0;
        while(!qu.empty()){
            int sz = qu.size();
            time++;
            // cout<<sz<<" : "<<time<<endl;
            while(sz--){
                pair<int,int> p = qu.front();
                qu.pop();
                // if(grid[p.first][p.second] = 2) continue;
                // grid[p.first][p.second] = 2;
                pushNodes(qu,p,grid);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)   return -1;
            }
        }

        return time-1;
    }
};