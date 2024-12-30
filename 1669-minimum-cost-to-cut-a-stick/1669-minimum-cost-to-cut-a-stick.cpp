class Solution {
public:

    int rec(int l1, int l2, vector<int> &arr, vector<vector<int>> &dp){
        if(l1+1>=l2)  return 0;
        if(dp[l1][l2]!=-1)  return dp[l1][l2];
        int ans = INT_MAX;
        for(int mid=l1+1; mid<l2; mid++){
            int lv = arr[l1], rv = arr[l2], mv = arr[mid];
            ans = min(ans, rec(l1,mid,arr,dp) + rec(mid,l2,arr,dp) + rv-lv);
        }
        return dp[l1][l2] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        vector<int> arr;
        for(auto x: cuts)   arr.push_back(x);
        arr.push_back(0);
        arr.push_back(n);
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, -1));
        int minCost = rec(0,arr.size()-1, arr, dp);
        return minCost;
    }
};