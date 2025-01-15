class Solution {
public:
    int N;
    vector<set<int>> boxCheck;
    vector<set<int>> rows;
    vector<set<int>> cols;
    bool flag;
    vector<vector<char>> boardCopy;

    void fillSudoku(int i, int j, vector<vector<char>>& board){
        if(j>=N){
            fillSudoku(i+1, 0, board);
            return;
        }
        if(i>=N){
            // for(auto v: board){
            //     for(auto c: v)  cout<<c<<" ";
            // }cout<<endl;
            flag = true;
            return;
        }

        if(board[i][j]!='.'){
            fillSudoku(i, j+1, board);
            return;
        }

        for(int x = 1; x<=N; x++){
            if(boxCheck[(i/3)*3 + (j/3)].find(x)==boxCheck[(i/3)*3 + (j/3)].end() && rows[i].find(x)==rows[i].end() && cols[j].find(x)==cols[j].end()){
                char c = '0' + x;
                // cout<<c<<" "<<x<<endl;
                board[i][j] = c;
                boxCheck[(i/3)*3 + (j/3)].insert(x);
                rows[i].insert(x);
                cols[j].insert(x);
                fillSudoku(i, j+1, board);
                if(flag)    return;
                board[i][j] = '.';
                boxCheck[(i/3)*3 + (j/3)].erase(x);
                rows[i].erase(x);
                cols[j].erase(x);
            }
        }
        return;
    }

    void solveSudoku(vector<vector<char>>& board) {
        N = board.size();
        cout<<N<<endl;
        boxCheck.resize(N);
        rows.resize(N);
        cols.resize(N);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(board[i][j]!='.'){
                    int x = board[i][j]-'0';
                    boxCheck[(i/3)*3 + (j/3)].insert(x);
                    // cout<<(i/3)*3 + (j/3)<<" ";
                    rows[i].insert(x);
                    cols[j].insert(x);
                }
            }//cout<<endl;
        }
        flag = false;

        fillSudoku(0, 0, board);
        // board = boardCopy;
        return;

    }
};