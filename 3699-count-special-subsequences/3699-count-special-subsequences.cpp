class Solution {
public:
    
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<double, int> ump;
        int n = nums.size();
        long long ans = 0;
        for(int r=4; r<n-2; r++){
            int q = r-2;
            for(int p=0; p<=q-2; p++){
                ump[(1.0 * nums[p])/nums[q]]++;
            }
            for(int s=r+2; s<n; s++){
                double val = (1.0*nums[s])/nums[r];
                ans += ump[val];
            }
        }
        return ans;
    }
};