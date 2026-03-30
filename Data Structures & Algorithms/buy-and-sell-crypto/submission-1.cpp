class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=INT_MIN;
        int buyPrice = prices[0];
        if(prices.size()<2) return 0;
        for(int right=1;right<prices.size();right++){
            if(buyPrice>prices[right]){
                buyPrice = prices[right];
            }
            maxProfit = max(maxProfit,prices[right]-buyPrice);
        }
        return maxProfit;
    }
};
