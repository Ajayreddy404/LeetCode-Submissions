class Solution {
public:

    void print(vector<int> arr){
        for(auto x: arr){
            cout<<x<<" ";
        }cout<<endl;
    }

    void rec(int lvl, vector<int>& candidates, vector<int> &chosen, vector<vector<int>> &ans, int rSum){
        if(rSum==0){
            // cout<<"h"<<endl;
            // print(chosen);
            ans.push_back(chosen);
            return;
        }
        if(rSum<0 || lvl==candidates.size())  return;
        // cout<<lvl<<" "<<rSum<<endl;
        if(candidates[lvl]<=rSum){
            chosen.push_back(candidates[lvl]);
            // cout<<candidates[lvl]<<" "<<lvl<<endl;
            rec(lvl, candidates, chosen, ans, rSum-candidates[lvl]);
            chosen.pop_back();
            // cout<<"popped: "<<lvl<<endl;
        }
        rec(lvl+1, candidates, chosen, ans, rSum);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> chosen;
        rec(0, candidates, chosen, ans, target);
        return ans;
    }
};