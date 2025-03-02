class Solution {
private:
    int m, n;
    vector<vector<bool>> vis;

    bool isEdgeReachable(int i, int j, vector<vector<char>>& board){
        if(i<0 || j<0 || i==m || j==n)  return true;
        if(board[i][j]=='X' || vis[i][j])    return false;
        vis[i][j] = true;
        bool fg = false;
        fg |= isEdgeReachable(i+1,j,board);
        fg |= isEdgeReachable(i-1,j,board);
        fg |= isEdgeReachable(i,j+1,board);
        fg |= isEdgeReachable(i,j-1,board);
        return fg;
    }

    void markX(int i, int j, vector<vector<char>>& board){
        if(i<0 || j<0 || i==m || j==n)  return;
        if(board[i][j]=='X')    return;
        board[i][j] = 'X';
        markX(i+1,j,board);
        markX(i-1,j,board);
        markX(i,j+1,board);
        markX(i,j-1,board);
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vis.assign(m, vector<bool> (n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    if(!isEdgeReachable(i,j,board)){
                        markX(i,j,board);
                    }
                }
            }
        }
    }
};