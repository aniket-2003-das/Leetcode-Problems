class Solution {
public:
    void traversal(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node]=1;
        for (int i=0; i<isConnected[node].size(); i++) {
            if (isConnected[node][i]==1 && !visited[i]) {
                traversal(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V, 0);
        int cnt=0;

        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                cnt++;
                traversal(i, isConnected, visited);
            }
        }
        return cnt;
    }
};