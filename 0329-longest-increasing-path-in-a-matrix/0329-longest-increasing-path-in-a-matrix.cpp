class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> len_arr(m, vector<int> (n,1));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                pq.push({matrix[i][j], {i,j}});
            }
        }

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while(!pq.empty()){
            pair<int,pair<int,int>> p = pq.top();
            int i = p.second.first;
            int j = p.second.second;
            pq.pop();
            for(int k=0; k<4; k++){
                int x = i+dx[k], y = j+dy[k];
                if(x<0 || x>=m || y<0 || y>= n) continue;
                if(matrix[x][y]>p.first){
                    len_arr[x][y] = max(len_arr[x][y], len_arr[i][j]+1);
                }
            }

        }

        int max_len = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                max_len = max(max_len, len_arr[i][j]);
                // cout<<len_arr[i][j]<<" ";
            }//cout<<endl;
        }
        return max_len;
    }
};