class Solution {
public:
    void print(vector<int> arr){
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void rec(int lvl, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp){
        // print(temp);
        ans.push_back(temp);
        for(int i=lvl; i<nums.size(); i++){
            if(i!=lvl && nums[i]==nums[i-1])    continue;
            // cout<<"i: "<<i<<endl;
            temp.push_back(nums[i]);
            rec(i+1, nums, ans, temp);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        rec(0, nums, ans, temp);
        return ans;
    }
};