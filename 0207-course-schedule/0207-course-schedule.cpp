class Solution {
public:
    bool isCyclePresent = false;

    void dfs(int node, vector<int>& vis, vector<vector<int>>& grp){
        if(vis[node]==1){
            isCyclePresent = true;
            return;
        }
        if(vis[node]==2)   return;
        vis[node] = 1;
        for(auto nd: grp[node]){
            dfs(nd, vis, grp);
        }
        vis[node] = 2;
    }

    void solve(int n, vector<vector<int>>& grp){
        vector<int> vis(n+1, 0);
        for(int i=1; i<=n; i++){
            if(vis[i]==0)   dfs(i, vis, grp);
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make graph - directed graph
        vector<vector<int>> grp(numCourses+1);
        for(auto edge: prerequisites){
            grp[edge[0]].push_back(edge[1]);
        }
        // check for cycle presence
        // if found -> cannot finish -> return false
        solve(numCourses, grp);
        if(isCyclePresent) return false;
        // else return true
        return true;
    }
};