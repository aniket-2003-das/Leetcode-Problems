class Solution {
public:
    void dfs(int src, vector<int>&visited, vector<vector<int>>&adjList, int &edges, int &nodes) {
        visited[src]=1;
        for(auto it: adjList[src]){
            edges++;
            if(visited[it]==0){
                nodes++;
                dfs(it, visited, adjList, edges, nodes);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edge) {
        vector<vector<int>> adjList(n);
        for(auto it: edge) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        vector<int>visited(n, 0);
        int edges=0;
        int nodes=1;
        int ans=0;

        for(int i=0; i<n; i++){
                if(visited[i]==0) {
                dfs(i, visited, adjList, edges, nodes);
                // expected number of edges in a complete graph with 'nodes' nodes.
                int no_eg=(nodes*(nodes-1))/2;
                // Check if the number of edges in the component matches no_eg
                if(edges/2==no_eg) ans++;
                edges=0;
                nodes=1;
            }
        }
        return ans;
    }
};