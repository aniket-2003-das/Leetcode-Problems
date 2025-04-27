class Solution {
    public:
        void dfs(int node, int time, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
            if(time>=dist[node]) return;
            dist[node]=time;
            for (auto it : adj[node]) {
                int neighbour = it.first;
                int weight = it.second;
                dfs(neighbour, time+weight, adj, dist);
            }
        }
    
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing
            for (auto it : times) {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                adj[u].push_back({v, w});
            }
            vector<int> dist(n + 1, INT_MAX);
            dfs(k, 0, adj, dist);
            
            int totalTime = 0;
            for(int i=1; i<=n; i++) {
                if(dist[i]==INT_MAX) return -1;
                totalTime=max(totalTime, dist[i]);
            }
            return totalTime;
        }
    };