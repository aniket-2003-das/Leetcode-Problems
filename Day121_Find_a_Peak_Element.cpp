class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0, high= m-1;

        while(low<=high){
            int maxRow=0;
            int midCol=(low+high)>>1;
            for(int row=0; row<n; row++){
                if(mat[row][midCol] > mat[maxRow][midCol]) maxRow = row;
            }

            int currElement= mat[maxRow][midCol];
            int leftElement=midCol == 0 ? -1 : mat[maxRow][midCol-1];
            int rightElement=midCol == m-1 ? -1 : mat[maxRow][midCol+1];

            if(currElement>leftElement && currElement>rightElement){
                return {maxRow, midCol};
            }
            else if(currElement < leftElement){
                high = midCol - 1;
            }
            else{
                low = midCol + 1;
            }
        }
        return {-1, -1};
    }
};