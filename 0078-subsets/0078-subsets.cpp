class Solution {
public:

    void rec(int l, vector<int> &cur, vector<int> &nums, vector<vector<int>> &res){
        if(l==nums.size()){
            res.push_back(cur);
            return;
        }
        rec(l+1,cur,nums,res);
        cur.push_back(nums[l]);
        rec(l+1,cur,nums,res);
        cur.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        rec(0,cur,nums,res);
        return res;
    }
};