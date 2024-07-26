class Solution {
public:
    vector<int> getRow(int n) {
        long long ans=1;
        vector<int> res;
        for(int i=0; i<=n; i++){
            res.push_back(ans);
            ans*=(n-i);
            ans/=(i+1);
        }
        return res;
    }
};