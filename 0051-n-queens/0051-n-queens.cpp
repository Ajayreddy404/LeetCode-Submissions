class Solution {
public:
    int N;
    set<int> ipj;
    set<int> imj;

    void findAllBoards(int row, vector<string> &board, vector<vector<string>> &res, set<int> &cols){
        if(row==N){
            if(cols.size()==N)  res.push_back(board);
            return;
        }

        for(int i=0; i<N; i++){
            if(cols.find(i)==cols.end() && ipj.find(i+row)==ipj.end() && imj.find(row-i)==imj.end()){
                board[row][i] = 'Q';
                cols.insert(i);
                ipj.insert(i+row);
                imj.insert(row-i);
                findAllBoards(row+1, board, res, cols);
                board[row][i] = '.';
                cols.erase(i);
                ipj.erase(i+row);
                imj.erase(row-i);
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        set<int> cols;
        
        vector<string> board;
        string s = "";
        for(int i=0; i<n; i++)  s += '.';
        for(int i=0; i<n; i++)  board.push_back(s);
        vector<vector<string>> res;
        findAllBoards(0, board, res, cols);
        return res;
    }
};