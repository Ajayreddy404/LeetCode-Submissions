class Solution {
public:
    

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        queue<pair<int,int>> pq;
        vector<vector<pair<int,int>>> grp(n+1);
        for(auto v: flights){
            grp[v[0]].push_back({v[1],v[2]});
        }

        pq.push({0,src});
        vector<int> dist(n+1, 1e8);
        dist[src] = 0;

        while(!pq.empty() && k>=0){
            int sz = pq.size();
            // cout<<"sz: "<<sz<<endl;
            while(sz--){
                int node = pq.front().second;
                int wt1 = pq.front().first;
                // cout<<node<<endl;
                pq.pop();
                for(auto p: grp[node]){
                    int wt = p.second;
                    int nd = p.first;
                    if(dist[nd] > wt+wt1){
                        dist[nd] = wt1+wt;
                        pq.push({dist[nd], nd});
                        // cout<<nd<<" "<<dist[nd]<<endl;
                    }
                }
                
            }
            k--;
        }

        if(dist[dst]>1e7)   return -1;
        return dist[dst];
    }
};