class Solution {
public:
    // settig colour for each connected component
    bool setColour(int i, vector<int>& col, vector<vector<int>>& grp){
        col[i] = 0;
        queue<int> qu;
        qu.push(i);
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                int node = qu.front();
                qu.pop();
                for(auto nd: grp[node]){
                    if(col[nd]==col[node])  return false;
                    else if(col[nd]==-1){
                        col[nd]= col[node]^1;
                        qu.push(nd);
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& grp) {
        int n = grp.size();
        // colour the nodes with alternate colours
        vector<int> col(n, -1); // -1 means not yet coloured
        
        for(int i=0; i<n-1; i++){
            if(col[i]==-1){
                if(!setColour(i, col, grp)) return false;
            }
        }
        return true;
    }
};