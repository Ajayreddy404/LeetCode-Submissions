class Solution {
public:

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> res;
        // topological sort - indegree of eachh node should be 0 finally
        vector<int> indegree(n,0);
        vector<vector<int>> grp(n+1);
        for(auto v: prerequisites){
            // edge from v[1] to v[0]: complete v[1] first, then only we can take v[0]
            grp[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> qu;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)  qu.push(i);
        }

        while(!qu.empty()){
            int node = qu.front();
            res.push_back(node);
            qu.pop();
            for(auto nd: grp[node]){
                indegree[nd]--;
                if(indegree[nd]==0) qu.push(nd);
            }
        }
        
        if(res.size()!=n)   return {};
        return res;
    }
};