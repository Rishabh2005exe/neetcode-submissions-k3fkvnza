class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP =0;
        int minB = prices[0];
        for(int &sell:prices)
        {
            maxP = max(maxP,sell-minB);
            minB = min(sell,minB);
        }
        return maxP;
    }
};
