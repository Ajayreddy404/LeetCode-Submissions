class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cnt(m+1, vector<int>(n+1,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='0')   cnt[i+1][j+1] = cnt[i][j+1] + cnt[i+1][j] - cnt[i][j];
                else cnt[i+1][j+1] = 1 + cnt[i][j+1] + cnt[i+1][j] - cnt[i][j];
            }
        }

        // for(int i=0; i<=m; i++){
        //     for(int j=0; j<=n; j++){
        //         cout<<cnt[i][j]<<" ";
        //     }cout<<endl;
        // }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(matrix[i][j]=='0')   continue;
                // int cur = 0;
                for(int k=1; k<=min(i,j)+1; k++){
                    int excluded = cnt[i+1-k][j+1] + cnt[i+1][j+1-k] - cnt[i+1-k][j+1-k];
                    int cur = cnt[i+1][j+1]-excluded;
                    if(cur==k*k){
                        maxArea = max(maxArea, cur);
                    }
                }
            }
        }
        return maxArea;

    }
};