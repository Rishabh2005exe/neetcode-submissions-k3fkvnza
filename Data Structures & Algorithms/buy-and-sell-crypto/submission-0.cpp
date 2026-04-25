class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest=prices[0];
        int max_profit=0;
        for(int i=1 ; i<prices.size() ;i++)
        {
            if(prices[i] < lowest)
                lowest = prices[i];


            int profit = prices[i]- lowest;
            profit = (profit>0) ? profit:0;
            max_profit = max(profit,max_profit);

        }
        return max_profit;
    }
};
