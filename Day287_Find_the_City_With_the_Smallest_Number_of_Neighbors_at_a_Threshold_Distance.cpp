class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> dist(n, vector<long long>(n, INT_MAX));
        for(auto it: edges){
            dist[it[0]] [it[1]] = it[2];
            dist[it[1]] [it[0]] = it[2];
        }

        for(int i=0; i<n; i++) dist[i][i]=0;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cnt_city = n;
        int cityNo = -1;
        for(int city=0; city<n; city++){
            int cnt=0;
            for(int adjcity=0; adjcity<n; adjcity++){
                if(dist[city][adjcity]<=distanceThreshold) 
                    cnt++;
            }
            if(cnt<=cnt_city){
                cnt_city=cnt;
                cityNo=city;
            }
        }
        return cityNo;
    }
};