class Solution{
public:
    int help(int i , vector<int>& prices , int bag , vector<vector<int>>& dp)
    {
        if(i >= prices.size())
        {
            return 0;
        }
        if(dp[i][bag] != -1)
        {
            return dp[i][bag];
        }
        if(bag == 1)
        {
            int opt2 = prices[i] + help(i+2,prices,0,dp);
            int opt3 = help(i+1,prices,1,dp);
            return dp[i][bag] = max(opt2,opt3);
        }
        else
        {
            int opt1 = -prices[i] + help(i+1,prices,1,dp);
            int opt3 = help(i+1,prices,0,dp);
            return dp[i][bag] = max(opt1,opt3);
        }
    }
    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return help(0,prices,0,dp);
    }
};
