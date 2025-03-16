class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
            greater<pair<long long, int>>> pq;
        vector<long long> dist(n , 1e18);
        vector<int> ways(n, 0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0, 0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edw = it.second;

                if(dis+edw < dist[adjNode]){
                    dist[adjNode] = dis+edw;
                    pq.push({dis+edw, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis+edw==dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};