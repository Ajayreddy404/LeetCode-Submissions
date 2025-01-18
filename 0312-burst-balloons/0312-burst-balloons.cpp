class Solution {
public:

    int maxCoins(int l, int r, vector<vector<int>> &dp, vector<int> &nums){
        if(l>r) return 0;
        if(dp[l][r]!=-1)    return dp[l][r];
        // if nums[k] is the last element to burst in the range nums(l,r)
        int ans = 0;
        for(int k=l; k<=r; k++){
            int ans2 = nums[k];
            if(l-1>=0)    ans2 *= nums[l-1];
            if(r+1<nums.size()) ans2 *= nums[r+1];
            ans = max(ans, ans2 + maxCoins(l,k-1,dp,nums) + maxCoins(k+1,r,dp,nums));
        }
        // cout<<l<<" "<<r<<" "<<ans<<endl;
        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        int ans = maxCoins(0,nums.size()-1,dp,nums);
        return ans;
    }
};