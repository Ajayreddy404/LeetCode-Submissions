class Solution {
public:
    int m,n,l;
    vector<vector<bool>> vis;
    bool ans;

    void dfs(vector<vector<char>>& board, string& word,int i, int j, int k){
        // cout<<i<<" "<<j<<" "<<k<<endl;
        if(k==l){
            // cout<<"here"<<endl;
            ans = true;
            return;
        }
        if(i<0 || j<0 || i>=n || j>=m)  return;
        if(vis[j][i])   return;
        
        vis[j][i] = true;
        if(word[k]==board[j][i]){
            dfs(board,word,i+1,j,k+1);
            dfs(board,word,i-1,j,k+1);
            dfs(board,word,i,j+1,k+1);
            dfs(board,word,i,j-1,k+1);
        }
        vis[j][i] = false;
        return;
    }

    bool exist(vector<vector<char>>& board, string word) {
        l = word.size();
        m = board.size();
        n = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vis.assign(m,vector<bool>(n,false));
                ans = false;
                dfs(board,word,i,j,0);
                if(ans) return true;
            }
        }
        return false;
    }
};