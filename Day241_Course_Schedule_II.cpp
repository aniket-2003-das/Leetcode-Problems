class Solution {
public:
    bool dfs(vector<vector<int>>& preList, int node, vector<int>& vis, vector<int>& ans){
        if (vis[node]==1) return true;
        if (vis[node] == 2) return false;
        vis[node] = 1;

        for (int it: preList[node]) {
            if (dfs(preList, it, vis, ans)) {
                return true; 
            }
        }
        vis[node] = 2;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preList(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for(auto it: prerequisites) {
            preList[it[0]].push_back(it[1]);
        }
        for(int i=0; i<numCourses; i++) {
            if (vis[i]==0) {
                if (dfs(preList, i, vis, ans)) return {};
            }
        }
        return ans;
    }
};