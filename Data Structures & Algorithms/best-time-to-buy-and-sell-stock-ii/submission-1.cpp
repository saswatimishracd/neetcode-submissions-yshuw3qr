class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit=0;
        int bp=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]<bp){
                bp=prices[i];
                continue;
            }
            if((prices[i]>prices[i-1] && prices[i]>prices[i+1])|| i==n-1 ){
                int sp=prices[i];
                maxProfit = maxProfit+sp-bp;
                bp=prices[i+1];
            }
        }
        return maxProfit;
    }
};