class Solution {
public:

    int rec(int l, int r, vector<vector<int>> &dp, string &s){
        if(l>r) return 0;
        if(l==r)    return 1;
        if(dp[l][r]!=-1)    return dp[l][r];
        int cnt = 0;
        if(s[l]==s[r])  cnt = 2 + rec(l+1, r-1, dp, s);
        else{
            cnt = max(rec(l+1, r, dp, s), rec(l, r-1, dp, s));
        }
        return dp[l][r] = cnt;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = rec(0, n-1, dp, s);
        return ans;
    }
};