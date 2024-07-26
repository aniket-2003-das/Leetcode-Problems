class Solution {
public:
    vector<int> returnRow(int n){
        vector<int> ans;
        int term=1;
        ans.push_back(1);
        for(int col=1; col<n; col++){
            term*=n-col;
            term/=col;
            ans.push_back(term);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(returnRow(i));
        }
        return ans;
    }
};