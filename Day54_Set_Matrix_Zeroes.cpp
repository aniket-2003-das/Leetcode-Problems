class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> col;
        for(int i=0; i< matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]==0){
                    rows.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i=0; i< col.size(); i++){
            int cols=col[i];
            for(int j=0; j<matrix.size(); j++){
                matrix[j][cols]=0;
            }
        }
         for(int i=0; i< rows.size(); i++){
            int row=rows[i];
            for(int j=0; j<matrix[row].size(); j++){
                matrix[row][j]=0;
            }
        }
        return ;
    }
};