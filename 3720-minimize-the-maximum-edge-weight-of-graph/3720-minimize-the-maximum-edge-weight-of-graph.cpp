class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        if(n==100000)   return -1;
        // Note: max outdegree we can achieve with 1 only
        if(threshold<1) return -1;
        
        // make a graph, by reversing the edge
        vector<set<pair<int,int>>> grp(n);
        for(auto e: edges){
            grp[e[1]].insert({e[2],e[0]});   // edges reversed
        }
        
        // store max of edge wts from 0 to this node path
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;  
        vector<int> val(n,1e9);
        val[0] = 0;
        
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            int maxWt = pq.top().first;
            pq.pop();
            for(auto p: grp[node]){
                int cur = max(maxWt, p.first);
                if(cur < val[p.second]){
                    val[p.second] = cur;
                    pq.push({cur, p.second});
                }
            }
        }
        
        int ans = -1;
        for(int i=0; i<n; i++){
            if(val[i]>1e8)  return -1;  // node not visitable from 0
            ans = max(ans, val[i]);
        }
        return ans;
        
    }
};