// class Solution {
// public:
//     bool check(int start, vector<vector<int>>& graph, vector<int> &colour){
//         queue<int> q;
//         q.push(start);
//         colour[start] = 0;
        
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             for(auto it: graph[node]){
//                 if(colour[it]==-1){
//                     colour[it]=!colour[node];
//                     q.push(it);
//                 }
//                 else if(colour[it]==colour[node]) return 0;
//             }
//         }
//         return 1;
//     }

//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> colour(n, -1);
//         for(int i=0; i<n; i++){
//             if(colour[i]==-1){
//                 if(check(i, graph, colour)==0) return 0;
//             }
//         }
//         return 1;
//     }
// };

class Solution {
public:
    bool check(int node, int col, vector<vector<int>>& graph, vector<int> &colour){
        colour[node] = col;
        for(auto it: graph[node]){
            if(colour[it]==-1){
                if(check(it, !col, graph, colour)==0) return 0;
            }
            else if(colour[it]==col) return 0;
        }
        return 1;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);
        for(int i=0; i<n; i++){
            if(colour[i]==-1){
                if(check(i, 0, graph, colour)==0) return 0;
            }
        }
        return 1;
    }
};