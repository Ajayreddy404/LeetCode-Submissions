class Solution {
    int getMaxSum(int ed0, int ed1, vector<set<pair<int,int>>>& grp, vector<int>& scores){
        // cout<<ed0<<" "<<ed1<<"; "<<endl;
        int maxSum = -1;
        for(auto p1: grp[ed0]){
            for(auto p2: grp[ed1]){
                
                if(p1.second!=ed1 && p2.second!=ed0 && p1.second!=p2.second){
                    // cout<<p1.second<<" "<<p2.second<<endl;
                    maxSum = max(maxSum, scores[p1.second] + scores[p2.second] + scores[ed0] + scores[ed1]);
                    cout<<maxSum<<endl;
                }
            }
        }
        return maxSum;
    }
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<set<pair<int,int>>> grp(n);
        for(auto e: edges){
            grp[e[0]].insert({scores[e[1]], e[1]});
            grp[e[1]].insert({scores[e[0]], e[0]});
            if(grp[e[0]].size()>3){
                grp[e[0]].erase(grp[e[0]].begin());
            }
            if(grp[e[1]].size()>3){
                grp[e[1]].erase(grp[e[1]].begin());
            }
        }

        // traverse every edge and check for max Scores
        int maxSum = -1;
        for(auto e: edges){
            maxSum = max(maxSum, getMaxSum(e[0], e[1], grp, scores));
        }

        return maxSum;
        
    }
};