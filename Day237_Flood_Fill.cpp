class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, int color, int delRow[], int delCol[], int iniColor) {
        ans[row][col] = color;
        int n = ans.size();
        int m = ans[0].size();

        for(int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==iniColor && ans[nrow][ncol]!=color){
                dfs(nrow, ncol, ans, color, delRow, delCol, iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, color, delRow, delCol, iniColor);
        return ans;
    }
};