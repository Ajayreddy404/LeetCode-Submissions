class Solution {
public:
    vector<int> mins;
    vector<int> maxs;
    int firstMinIndex = -1;

    vector<int> getMins(vector<int> &arr){
        int n = arr.size();
        vector<int> mins;
        if(n==0)    return mins;
        if(n==1)    return {arr[0]};
        //first element is min
        if(arr[0]<arr[1]){
            mins.push_back(arr[0]);
            if(firstMinIndex==-1)   firstMinIndex = 0;
        }
        // middle mins
        for(int i=1; i<n-1; i++){
            if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
                mins.push_back(arr[i]);
                if(firstMinIndex==-1)   firstMinIndex = i;
            }
        }
        // last element min
        if(arr[n-1]<arr[n-2]){
            mins.push_back(arr[n-1]);
            if(firstMinIndex==-1)   firstMinIndex = n-1;
        }
        return mins;
    }

    vector<int> getMaxs(vector<int> &arr){
        int n = arr.size();
        vector<int> maxs;
        if(n==0)    return maxs;
        if(n==1)    return {arr[0]};
        //first element is max
        // if(arr[0]>arr[1] && firstMinIndex<0)   maxs.push_back(arr[0]);
        // middle mins
        for(int i=1; i<n-1; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1] && firstMinIndex<i){
                maxs.push_back(arr[i]);
            }
        }
        // last element min
        if(arr[n-1]>arr[n-2] && firstMinIndex<n-1){
            maxs.push_back(arr[n-1]);
        }
        return maxs;
    }

    int rec(int i, int t, vector<vector<int>> &dp){
        if(t==0)  return 0;
        if(i==maxs.size())  return 0;
        if(dp[i][t]!=-1)    return dp[i][t];
        int maxP = 0;
        // considering mins[i]
        for(int j=i; j<maxs.size(); j++){
            int diff = maxs[j]-mins[i];
            if(diff) maxP = max(maxP, diff + rec(j+1, t-1, dp));
        }
        // not considering mins[i]
        maxP = max(maxP, rec(i+1, t, dp));
        return dp[i][t] = maxP;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<int> arr;
        arr.push_back(prices[0]);
        for(int i=1; i<prices.size(); i++){
            if(prices[i]!=arr.back())   arr.push_back(prices[i]);
        }
        mins = getMins(arr);
        maxs = getMaxs(arr);
        // dp[i][j] = max profit with j transactions(buy+sell) in mins(i:) and maxs(i:);
        vector<vector<int>> dp(mins.size()+1, vector<int>(k+1,-1));
        int ans = rec(0, k, dp);
        return ans;
    }
};