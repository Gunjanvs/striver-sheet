#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    // buy  -=== 1 means it obught
public:
    int f(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (dp[index][buy] != -1)
            return dp[index][buy];
        if (buy == 0)
        {
            // sell it
            int bought = -prices[index] + f(index + 1, 1, prices, dp);
            int nbought = f(index + 1, 0, prices, dp);
            return dp[index][buy] = max(bought, nbought);
        }
        else
        {
            int sell = prices[index] + f(index + 1, 0, prices, dp);
            int nsell = f(index + 1, 1, prices, dp);
            return dp[index][buy] = max(nsell, sell);
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // Initialize DP array with 0

        dp[n][0] = dp[n][1] = 0; // Base cases: if index is n, profit is 0

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    // Buy the stock or skip buying
                    int bought = -prices[index] + dp[index + 1][0];
                    int nbought = dp[index + 1][1];
                    profit = max(bought, nbought);
                }
                else
                {
                    // Sell the stock or skip selling
                    int sell = prices[index] + dp[index + 1][1];
                    int nsell = dp[index + 1][0];
                    profit = max(sell, nsell);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1]; // We start with the decision to buy
    }
};