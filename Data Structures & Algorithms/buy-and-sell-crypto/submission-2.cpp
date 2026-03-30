class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice=prices[0];
        int maxProfit = 0;
        if(prices.size()==1) return maxProfit;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buyPrice){
                buyPrice = prices[i];
            }
            else{
                maxProfit=max(maxProfit,prices[i]-buyPrice);
            }
        }
        return maxProfit;
    }
};
