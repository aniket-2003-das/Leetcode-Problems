class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0, profit, mini=prices[0];
        for(int i=1; i<prices.size(); i++){
            profit=prices[i]-mini;
            maxprofit=max(maxprofit, profit);
            mini=min(mini, prices[i]);
        }
        return maxprofit;  
    }
};