class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: flights) adj[it[0]].push_back({it[1], it[2]});
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src]=0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int cost = it.second.second;
            int node = it.second.first;

            if(stops>k) continue;
            for(auto iter: adj[node]){
                int adjtNode = iter.first;
                int edw = iter.second;
                if(cost+edw < dist[adjtNode] && stops<=k){
                    dist[adjtNode] = cost + edw;
                    q.push({stops+1, {adjtNode, cost+edw}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};