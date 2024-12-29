class Solution {
public:
    int dp[501][501];
    int n1, n2;

    int rec(int l1, int l2, string& s1, string& s2){
        
        if(l1==n1 || l2==n2){
            // cout<<l1<<l2<<" "<<abs((n1-l1)-(n2-l2))<<endl;
            return dp[l1][l2] = abs((n1-l1)-(n2-l2));
        }
        if(dp[l1][l2]!=-1)  return dp[l1][l2];
        int ans = 1e7;
        if(s1[l1]==s2[l2]) 
            ans = rec(l1+1,l2+1,s1,s2); //equal
        
        int r1 = n1-l1;
        int r2 = n2-l2;
        // replace
        ans = min(ans, rec(l1+1,l2+1,s1,s2)+1);
        // insert
        // if(r1<r2)   
        ans = min(ans, rec(l1,l2+1,s1,s2)+1);
        // delete
        // if(r1>r2)   
        ans = min(ans, rec(l1+1,l2,s1,s2)+1);
            
        // cout<<l1<<l2<<ans<<endl;
        return dp[l1][l2] = ans;
    }

    int minDistance(string word1, string word2) {
        n1 = word1.length();
        n2 = word2.length();
        // cout<<n1<<n2<<endl;
        memset(dp,-1,sizeof(dp));
        
        int ans = rec(0,0,word1,word2);
        // for(int i=1; i<=n1; i++){
        //     if(dp[i][0]==-1)    continue;
        //     ans = min(ans, dp[i][0]);
        //     cout<<i<<ans<<"jkj"<<endl;
        // }
        // for(int i=1; i<=n2; i++){
        //     if(dp[0][i]==-1)    continue;
        //     ans = min(ans, dp[0][i]);
        //     cout<<i<<ans<<" ygjhb"<<endl;
        // }
        return ans;
    }
};