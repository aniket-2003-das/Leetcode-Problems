class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(),sum=0;
        vector<int> s;

        for(int i=0; i<n; i++) {
            for(int j=0; j<grid[i].size(); j++) {
                sum+=grid[i][j];
                s.push_back(grid[i][j]);
            }
        }
        sort(s.begin(),s.end());
        vector<int> ans(2);
        
        for(int i=0; i<s.size(); i++) {
            if(i>0 && s[i]==s[i-1]) {
                ans[0]=s[i-1];
            }
        }

        int m=n*n;
        int count=(m*(m+1))/2;
        
        ans[1]=count-(sum-ans[0]);
        return ans;
    }
};