class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        int buyPrice = prices[0],maxProfit=INT_MIN;;
        for(int i=1;i<n;i++){
            if(prices[i]<buyPrice){
                buyPrice = prices[i];
            }
            maxProfit=max(maxProfit,prices[i]-buyPrice);
        }
        return maxProfit;
    }
};
