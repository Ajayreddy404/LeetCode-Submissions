class Solution {
public:

    bool rec(int lvl, int rsum, vector<int> &nums, vector<vector<int>> &dp){
        if(rsum==0) return true;
        if(lvl==nums.size() || rsum<0)    return false;
        if(dp[lvl][rsum]!=-1)   return (dp[lvl][rsum]==0) ? false : true;
        bool ans = false;
        ans = rec(lvl+1, rsum-nums[lvl], nums, dp) || rec(lvl+1, rsum, nums, dp);
        return dp[lvl][rsum] = ans;
    }

    bool canPartition(vector<int>& nums) {
        int rsum = 0;
        for(auto x: nums)   rsum+=x;
        if(rsum%2) return false;
        rsum /= 2;
        vector<vector<int>> dp(nums.size(), vector<int>(rsum+1, -1));
        return rec(0, rsum, nums, dp);
    }
};