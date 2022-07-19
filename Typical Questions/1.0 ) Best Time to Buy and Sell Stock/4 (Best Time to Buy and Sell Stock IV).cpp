class Solution {
public:
    int help(vector<int>& prices)
    {
        int net_profit = 0;
        for(int i = 1 ; i < prices.size() ; i++)
        {
            if(prices[i] > prices[i-1])
            {
                net_profit += prices[i] - prices[i-1];
            }
        }
        return net_profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        if(k<=0||prices.size() <=0)
        {
            return 0;
        }
        if(k>prices.size()/2)
        {
            return help(prices);
        }
        
        
        
        int min_price[k];
        int max_profit[k];
        for(int i = 0 ; i < k ; i++)
        {
            min_price[i] = INT_MAX;
            max_profit[i] = 0;
        }
        for(int i = 0 ; i < prices.size() ; i++)
        {
            for(int j = 0 ; j < k ; j++)
            {
                min_price[j] = min(min_price[j],prices[i]-(j>0?max_profit[j-1]:0));
                max_profit[j] = max(max_profit[j],prices[i] - min_price[j]);
            }
              
        }
        return max_profit[k-1];
        
        
    }
};
