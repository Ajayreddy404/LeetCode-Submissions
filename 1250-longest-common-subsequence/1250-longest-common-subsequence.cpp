class Solution {
public:
    int rec(int l1, int l2, string& text1, string& text2, vector<vector<int>>& dp){
        if(l1>=text1.size() || l2>=text2.size())    return 0;
        if(dp[l1][l2]!=-1)  return dp[l1][l2];
        int clen = 0;
        if(text1[l1]==text2[l2])    clen = 1+rec(l1+1,l2+1,text1,text2,dp);
        else{
            clen = max(rec(l1+1,l2,text1,text2,dp), rec(l1,l2+1,text1,text2,dp));
        }
        return dp[l1][l2] = clen;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        dp[0][0] = rec(0,0,text1,text2,dp);
        return dp[0][0];
    }
};